#include<stdio.h>
int main()
{
    int N,start,end, ph_counter = 0;
    scanf("%d %d %d",&N,&start,&end);

    long long int phone_prices_list[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&phone_prices_list[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (phone_prices_list[i]>=start && phone_prices_list[i]<=end)
        {
            ph_counter++;
        }
        
    }

    printf("%d",ph_counter);    
    
    return 0;
}