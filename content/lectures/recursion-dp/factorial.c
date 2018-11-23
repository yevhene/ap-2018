#include <stdio.h>
#include <cs50.h>

long long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n = get_int("Enter n: ");
    printf("%lld\n", factorial(n));
}