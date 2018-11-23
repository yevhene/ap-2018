#include <stdio.h>
#include <cs50.h>

long long fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = get_int("Enter n: ");
    printf("%lld\n", fib(n));
}