// This code shows how to iterate through all of the possible strings with lengths 0, 1 or 2
// condiotnal on the fact, that alphabert has only two letters - 'a' and 'b' (and their upper-case equivalents)
// Code might be useful as a starting point for task "Crack"
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{

    // all of the symbols from the alphabet + '\0' character
    // the presence of '\0' allows to iterate through strings with length less than 2
    string alphabet = "aAbB\0";

    // length of the alphabet including '\0' character
    // we can't use strlen here (if you are a student - think why)
    int alphabetLength = 5;
    // we will say the generated strings in this variable
    char password[3];
    password[2] = '\0';
    for (int i = 0; i < alphabetLength; ++i)
    {
        for (int j = 0; j < alphabetLength; ++j)
        {
            password[0] = alphabet[i];
            password[1] = alphabet[j];
            printf("%s\n", password);
        }
    }

}