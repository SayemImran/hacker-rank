#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int isSort = 1;
        int n;
        cin>>n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        
        for (int i = 0; i < n-1; i++)
        {
            if(v[i]>v[i+1]){
                isSort = 0;
                break;
            }
        }

        if(isSort){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        

    }
    

    return 0;
}