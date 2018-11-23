#include <stdio.h>
#include <cs50.h>

int main()
{
    int n = get_int("Enter n: ");
    printf("Enter prices:\n");

    // costs of individual pieces
    int *cost = malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d",&cost[i]);
    }
    // cost of optimal cutting for each length
    int *opt = malloc((n + 1) * sizeof(int));
    // the length of the first cut needed to achieve optimal cost for each length
    int *how = malloc((n + 1) * sizeof(int));

    opt[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        opt[i] = cost[i];
        how[i] = i;
        // iterate through all possible cuts and try to make answer better
        for (int j = 1; j < i; ++j)
        {
            if (cost[j] + opt[i - j] > opt[i])
            {
                opt[i] = cost[j] + opt[i - j];
                how[i] = j;
            }
        }
    }
    printf("Optimal cost: %d\n", opt[n]);
    printf("Parts:\n");
    int length = n;
    // restoring parts one by one
    while (length > 0)
    {
        printf("%d ", how[length]);
        length -= how[length];
    }
    printf("\n");

    // freeing the memory
    free(cost);
    free(opt);
    free(how);

}