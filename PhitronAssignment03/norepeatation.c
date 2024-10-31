#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int datas[n];
    int freq[100002] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &datas[i]);
        freq[datas[i]]++;
    }
    int count = 0;
    for (int i = 0; i < 100002; i++)
    {
        if (freq[i] == 1)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}