#include<stdio.h>
int main()
{
    int n=6;

    for (int row = 1; row <=n; row++)
    {
        for (int col = 1; col <=row; col++)
        {
            printf("%d ",col);
        }
        printf("\n");
        
    }
    
    return 0;
}