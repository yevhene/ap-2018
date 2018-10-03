// encrypts the plain text using algorithm, similar to Vigenere cipher algorithm
// the difference is that it uses dates for ciphering
// it is expected that the date will be provided as a command line argument without spaces and other non-digital characters

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    // simple check for number of command line arguments.
    // remember, that argv[0] is always a program name (and therefore when we run ./date-cipher 16081992 argc equals 2)
    if (argc != 2)
    {
        return 1;
    }
    // reading date from command line arguments
    string date = argv[1];
    string plainText = get_string("Enter plain text: ");

    // dateIndex keeps track of index of the character in date to use for ciphering
    int dateIndex = 0;
    int dateLength = strlen(date);



    for (int i = 0, n = strlen(plainText); i < n; ++i)
    {
        if (isalpha(plainText[i]))
        {
            // do the ciphering
            int shift = date[dateIndex] - '0';
            dateIndex++;
            if (dateIndex == dateLength)
            {
                dateIndex = 0;
            }
            // small letters
            if (islower(plainText[i]))
            {
                int letterNumber = plainText[i] - 'a';
                int cipheredLetterNumber = letterNumber + shift;
                if (cipheredLetterNumber >= 26)
                {
                    cipheredLetterNumber -= 26;
                }
                // cipheredLetterNumber = cipheredLetterNumber % 26;
                printf("%c", 'a' + cipheredLetterNumber);
            }
            // capital letters
            else
            {
                int letterNumber = plainText[i] - 'A';
                int cipheredLetterNumber = letterNumber + shift;
                if (cipheredLetterNumber >= 26)
                {
                    cipheredLetterNumber -= 26;
                }
                // cipheredLetterNumber = cipheredLetterNumber % 26;
                printf("%c", 'A' + cipheredLetterNumber);
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}