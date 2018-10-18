#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover <filename>\n");
        return 1;
    }

    // open infile & check for NULL
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    FILE *img;
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    int counter = 0;
    unsigned char buffer[512];

    // checks for end of file
    while (fread(&buffer, 512, 1, inptr) == 1)
    {
        // check for start of .jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // closes last img file
            if (counter > 0)
            {
                fclose(img);
            }
            char filename[8];
            // naming file after counter to 3 digits
            sprintf(filename, "%.3i.jpg", counter);
            // create file
            img = fopen(filename, "w");

            if (img == NULL)
            {
                fclose(inptr);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            counter++;
        }
        // skips writing if no jpg found
        if (counter == 0)
        {
            continue;
        }
        fwrite(buffer, 512, 1, img);

    }
    fclose(inptr);
    fclose(img);
    return 0;
}
