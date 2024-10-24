#include<stdio.h>
int main()
{
    int n, t, sum = 0, book_counter = 0;
    scanf("%d %d",&n,&t);
    long long int books[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&books[i]);
    }

    for (int i = 0; i < n; i++)
    {
       sum=sum+books[i];
       if (sum<=t)
       {
        book_counter++;
       }
       
    }
    printf("%d",book_counter);
    
    return 0;
}