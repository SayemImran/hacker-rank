#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int check = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != 1)
                {
                    check = 0;
                    break;
                }
            }
            else
            {
                if (arr[i][j] != 0)
                {
                    check = 0;
                    break;
                }
            }
        }
    }

    if (check)
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}