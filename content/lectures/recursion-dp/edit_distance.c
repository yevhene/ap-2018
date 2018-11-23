#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main()
{
    string first = get_string("Enter first string: ");
    string second = get_string("Enter second string: ");

    int n = strlen(first);
    int m = strlen(second);
    int **cost = malloc((n + 1) * sizeof(int*));
    int **how = malloc((n + 1) * sizeof(int*));

    for (int i = 0; i <= n; ++i)
    {
        cost[i] = malloc((m + 1) * sizeof(int));
        how[i] = malloc((m + 1) * sizeof(int));
    }

    for (int i = n; i >= 0; --i)
    {
        for (int j = m; j >= 0; --j)
        {
            if (i == n)
            {
                cost[i][j] = 2 * (m - j);
            } else if (j == m)
            {
                cost[i][j] = 2 * (n - i);
            } else
            {
                how[i][j] = 0;
                cost[i][j] = 2 + cost[i + 1][j];
                if (2 + cost[i][j + 1] < cost[i][j])
                {
                    how[i][j] = 1;
                    cost[i][j] = 2 + cost[i][j + 1];
                }

                int x = 0;
                if (first[i] != second[j])
                {
                    x = 1;
                }
                if (x + cost[i + 1][j + 1] < cost[i][j])
                {
                    how[i][j] = 2;
                    cost[i][j] = x + cost[i + 1][j + 1];
                }
            }
        }
    }
    printf("Cost: %d\n", cost[0][0]);
    int x = 0;
    int y = 0;
    while ((x < n) || (y < m))
    {
        if (x == n)
        {
            y++;
            printf("Insert\n");
        } else if (y == m)
        {
            x++;
            printf("Delete\n");
        } else if (how[x][y] == 0)
        {
            x++;
            printf("Delete\n");
        }
        else if (how[x][y] == 1)
        {
            y++;
            printf("Insert\n");
        } else
        {
            x++;
            y++;
            printf("Match\n");
        }
    }

    for (int i = 0; i < n; ++i)
    {
        free(cost[i]);
        free(how[i]);
    }
    free(cost);
    free(how);

}