#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);

    while (t--)
    {
        int inp;
        scanf("%d",&inp);

        for (int i = 1; i <=inp; i++)
        {
            printf("%d ",i);
            if (i==inp)
            {
                for (int j = inp-1; j >=1; j--)
                {
                    printf("%d ",j);
                }
            }
            
        }
        printf("\n");
        
    }
    
    return 0;
}