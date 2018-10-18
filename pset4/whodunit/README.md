# Questions

## What's `stdint.h`?

a header file that allows programmers to write more portable code by providing a set of typedefs that specify exact-width integer  types together with defined min/max allowable values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

makes it clear that you intend to use the data a specific way. it takes a fixed amount of memory. unsigned # of bits. ex: uint16_t range 0 through 65535.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 1
DWORD: 4
LONG: 4
WORD: 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII: BM, dex: 6677 hex: 0x424d

## What's the difference between `bfSize` and `biSize`?

bfSize: The size, in bytes, of the bitmap file.
biSize: The number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

the bitmap is top down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

if the file cannot be found

## Why is the third argument to `fread` always `1` in our code?

specifies how many elements to read, and we're always reading a struct so we only need 1.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

padding = ( 4 - (bi.width * sizeof(RGBTRIPLE)) % 4) % 4
padding = ( 4 - (3 * 3)) % 4) % 4
padding = 3

## What does `fseek` do?

sets the filne position of the stream to the given offset.

## What is `SEEK_CUR`?

flag that determines the originating position of the fseek file operation.

## Whodunit?

It was Professor Plum with the candlestick in the library.
