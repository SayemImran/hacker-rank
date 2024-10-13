#include<stdio.h>
int main(){
    int n, zero=0, one=0;
    scanf("%d",&n);

    int numbers[n];

    for(int i=0; i < n; i++){
        scanf("%d",&numbers[i]);
    }
    for(int i=0; i < n; i++){
        if(numbers[i]==0){
            zero++;
        }
        else{
            one++;
        }
    }
    printf("%d %d",zero,one);


    return 0;
}
