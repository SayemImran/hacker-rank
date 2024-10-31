#include<stdio.h>
int main()
{
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);

    int matrix[n][m];
    int frequency[1000] = {0};
    // array input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&matrix[i][j]);
            frequency[matrix[i][j]]++; // we set the frequency index according to matrix input value
        }
        
    }

    for (int i = 0; i < x; i++)
    {
        int data;
        scanf("%d",&data);
        printf("%d\n",frequency[data]); // here we prints the value at that index we want to find
    }
    
    
    return 0;
}