#include<stdio.h>

int main(){
    int n, max;
    scanf("%d",&n);
    long long int salamiList[n];

    for(int i = 0; i < n; i++){
        scanf("%lld",&salamiList[i]);
    }
    max = salamiList[0];

    for(int i=0; i < n; i++){
        if(salamiList[i]>=max){
            max = salamiList[i];
        }
    }
     for(int i=0; i < n; i++){
        printf("%lld ",max-salamiList[i]);
    }

    return 0;
}
