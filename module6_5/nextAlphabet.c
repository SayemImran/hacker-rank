#include<stdio.h>
int main()
{
    char ch;
    scanf("%c",&ch);
    if (ch)
    {
        if (ch == 'z')
        {
            printf("a");
        }
        else if(ch == 'Z'){
            printf("A");
        }
        else{
        ++ch;
        printf("%c",ch);
        }
    }    
    return 0;
}



// accepted