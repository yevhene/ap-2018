#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    // converts number like 4.36 (amount of money in dollars) to 436 (amount of money in cents)
    // might be useful for Cash task from pset1
    float sum = get_float("Enter sum: ");
    int sumInCents = (int)round(sum * 100);
    printf("%d\n", sumInCents);
}