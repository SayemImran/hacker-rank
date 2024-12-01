#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string nm;
    int cls;
    char s;
    int id;
};
int main()
{
    int n;
    cin>>n;
    Student arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].nm>>arr[i].cls>>arr[i].s>>arr[i].id;
    }
    for (int i = 0; i < n/2 ; i++)
    {
        int j = n-i-1;
        char tmp = arr[i].s;
        arr[i].s = arr[j].s;
        arr[j].s = tmp;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i].nm<<" "<<arr[i].cls<<" "<<arr[i].s<<" "<<arr[i].id<<endl;
    }
    
    return 0;
}