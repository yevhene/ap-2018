// Helper functions for music

#include <cs50.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
// 1/8
// 3/4 = 6 / 8
// 1/2 = 4/8

int duration(string fraction)
{
    int nominator = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    // nominator / denominator = x / 8
    // x = 8 * nominator / denominator
    return 8 * nominator / denominator;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    return false;
}
