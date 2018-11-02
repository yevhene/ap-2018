// calculates number of jpg files hidden in the input file
#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "./recover-template infile\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    int count = 0;

    unsigned char *block = malloc(BLOCK_SIZE * sizeof(char));

    // read input
    while (fread(block, sizeof(unsigned char), BLOCK_SIZE, inptr) > 0)
    {
        // check if it is a beginning of jpg
        if ((block[0] == 255) && (block[1] == 216) && (block[2] == 255) && (block[3] >= 224) && (block[3] <= 239))
        {
            count++;
        }
    }

    printf("%d\n", count);
    // success
    return 0;
}
