#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    getline(cin, name);

    stringstream ss(name);
    string nc;
    while (ss >> nc)
    {
        if(nc == "Jessica")
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
