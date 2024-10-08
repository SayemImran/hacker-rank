#include <stdio.h>
int main()
{
    int n, fd, sd;
    scanf("%d", &n);
    if (n >= 10 && n <= 99)
    {
        if (n / 10 == 0 || n % 10 == 0)
        {
            printf("YES");
        }
        else
        {
            sd = n % 10;
            fd = n / 10;
            if (fd % sd == 0 || sd % fd == 0)
            {
                printf("YES");
            }
            else
            {
                printf("NO");
            }
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

//  accepted