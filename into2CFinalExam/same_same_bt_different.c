#include <stdio.h>
#include <string.h>
int main()
{
    char str1[101],str2[101],str3[101];
    scanf("%s\n%s\n%s",str1,str2,str3);
    int counter = 0;
    int len = strlen(str1);
    for (int i = 0; i < len; i++)
    {
        if (str1[i] == str2[i] && str1[i] == str3[i])
        {
            continue;
        }
        else if(str1[i] == str2[i] || str1[i] == str3[i] || str2[i] == str3[i]){
            counter+=1;
        }
        else{
            counter+=2;
        }
        
    }
    

    printf("%d\n",counter);
    return 0;
}