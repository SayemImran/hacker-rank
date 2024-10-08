#include<stdio.h>
int main()
{
    int n=5;

    for (int row = n; row >= 1; row--)
    {
        for (int col = row; col >= 1; col--)
        {
            printf("%d ", col);
        }
        printf("\n");
        
    }
    
    return 0;
}