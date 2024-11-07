#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int jadu = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j || j == m - i - 1)
            {
                if (matrix[i][j] != 1)
                {
                    jadu = 0;
                    break;
                }
            }
            else
            {
                if (matrix[i][j] != 0)
                {
                    jadu = 0;
                    break;
                }
            }
        }
        if (!jadu)
        {
            break;
        }
    }

    if (jadu)
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    

        return 0;
    }