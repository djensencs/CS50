#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    // remember filenames & scale size
    int scale = atoi(argv[1]);

    if (scale < 1 || scale > 100)
    {
        fprintf(stderr, "n must be a positive integer less than or equal to 100\n");
        return 2;
    }
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // create outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    BITMAPFILEHEADER outbf = bf;
    BITMAPINFOHEADER outbi = bi;

    // rescale new width and height for the outfile
    outbi.biWidth *= scale;
    outbi.biHeight *= scale;

    // determine padding for scanlines of infile & outfile
    int in_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (outbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine the outfile biSizeImage and bfsize (biSizeImage + 54 bytes header files)
    outbi.biSizeImage = abs(outbi.biHeight) * (outbi.biWidth * sizeof(RGBTRIPLE) + out_padding);
    outbf.bfSize = (outbi.biSizeImage + 54);

    // write outfile BITMAPFILE HEADER & BITMAPINFOHEADER
    fwrite(&outbf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&outbi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < scale; j++)
        {
            // set pointer to beginning of line
            fseek(inptr, 54 + (bi.biWidth * 3 + in_padding) * i, SEEK_SET);

            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temp storage
                RGBTRIPLE triple;

                // read RGBTRIPLE from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // iterate over each pixel n times
                for (int l = 0; l < scale; l++)
                {
                    //write RGB to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // then add it bak to outfile
            for (int y = 0; y < out_padding; y++)
            {
                fputc(0x00, outptr);
            }
        }

    }
    // close files
    fclose(inptr);
    fclose(outptr);
    return 0;
}
