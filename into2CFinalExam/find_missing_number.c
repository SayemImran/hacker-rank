#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);

    while (t--)
    {
        long long int M;
        int A,B,C;
        scanf("%lld %d %d %d",&M,&A,&B,&C);
        long long int mult = (A*B*C);
        if (M % mult == 0)
        {
            int d = M / mult;
            printf("%lld\n",d);
        }
        else{
            printf("-1\n");
        }   
    }
    return 0;
}