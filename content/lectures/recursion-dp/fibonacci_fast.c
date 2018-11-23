#include <stdio.h>
#include <cs50.h>

const int MAXN = 80;

bool calculated[MAXN + 1];
long long cache[MAXN + 1];

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
    if (!calculated[n])
    {
        cache[n] = fib(n - 1) + fib(n - 2);
        calculated[n] = 1;
    }
    return cache[n];
}

int main()
{
    int n = get_int("Enter n: ");
    if (n > MAXN)
    {
        fprintf(stderr, "n is too big!");
        return 1;
    }
    printf("%lld\n", fib(n));
}