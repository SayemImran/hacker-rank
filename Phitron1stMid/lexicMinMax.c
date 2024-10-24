#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1005],str2[1005],str3[1005];
    scanf("%s %s %s",&str1,&str2,&str3);

// min string
    if (strcmp(str1,str2)<0 && strcmp(str1,str3)<0)
    {
        printf("%s\n",str1);
    }
    else if (strcmp(str2,str1)<0 && strcmp(str2,str3)<0)
    {
        printf("%s\n",str2);
    }
    else{
        printf("%s\n",str3);
    }
// max satring
    if (strcmp(str1,str2)>0 && strcmp(str1,str3)>0)
    {
        printf("%s\n",str1);
    }
    else if (strcmp(str2,str1)>0 && strcmp(str2,str3)>0)
    {
        printf("%s\n",str2);
    }
    else{
        printf("%s\n",str3);
    }
    
    return 0;
}