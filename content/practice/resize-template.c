// Makes an image n times wider

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    int n = atoi(argv[1]);
    if ((n < 1) || (n > 100))
    {
        fprintf(stderr, "./resize-template n infile outfile\n");
        return 1;
    }


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
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
        return 4;
    }


    // update BITMAPINFOHEADER
    int inputHeight = bi.biHeight;
    int inputWidth = bi.biWidth;
    bi.biWidth *= n;

    // determine padding for scanlines
    int inputPadding = (4 - (inputWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outputPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update BITMAPFILEHEADER
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + outputPadding) * abs(bi.biHeight);
    bf.bfSize = (bi.biWidth * sizeof(RGBTRIPLE) + outputPadding) * abs(bi.biHeight) + 54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(inputHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < inputWidth; j++)
        {

            RGBTRIPLE triple;
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int times = 0; times < n; ++times)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

        }

        // skip over padding, if any
        fseek(inptr, inputPadding, SEEK_CUR);

        // add padding
        for (int k = 0; k < outputPadding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
