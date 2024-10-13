#include<stdio.h>
int main(){
    int n, x;
    scanf("%d",&n);
    int numbers[n];
    for(int i=0; i < n; i++){
        scanf("%d",&numbers[i]);
    }
    scanf("%d",&x);

    if(numbers[x-1]==0){
        numbers[x-1] = 1;
    }
    else if(numbers[x-1] == 1){
        numbers[x-1] = 0;
    }
    for(int i = 0; i < n; i++){
        printf("%d ",numbers[i]);
    }
    return 0;
}

