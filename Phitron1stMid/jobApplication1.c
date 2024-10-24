#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int candidates[N];
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&candidates[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (candidates[i] <= 1)
        {
            printf("Entry-level candidate\n");
        }
        else if(candidates[i] >1 && candidates[i]<=3){
            printf("Junior candidate\n");
        }
        else if(candidates[i] >= 4 && candidates[i] <= 7){
            printf("Mid-level candidate\n");
        }
        else if(candidates[i]>7){
            printf("Senior candidate\n");
        }
        
    }
    
    
    return 0;
}


// If experience is less than 1, it's "Entry-level candidate".
// If experience is between 1 and 3 (inclusive), it's "Junior candidate".
// If experience is between 4 and 7 (inclusive), it's "Mid-level candidate".
// If experience is greater than 7, it's "Senior candidate".