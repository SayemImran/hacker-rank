#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d",&data);
        arr[i] = data;
        arr = (int*)realloc(arr,(i+2) * sizeof(int)); // here we increased i+2 cz we need space for next value
    }
    
    for (int i = 0; i < n; i++)
    {
    printf("%d ",arr[i]);
    }
    
    return 0;
}

// এখানে নতুন জিনিস শিখলাম।।
/*
    কীভাবে আগে এক রকম সাইজ ডিক্লেয়ার করে পরে আবার অইটা পুনরায় বাড়ানো যায় মান নেয়ার সাথে সাথে
*/