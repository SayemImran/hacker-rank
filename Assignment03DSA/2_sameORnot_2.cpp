#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> stackValues;
    vector<int> queueValues;

    if (n != m)
    {
        cout << "NO" << endl;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            stackValues.push_back(data);
        }

        for (int i = 0; i < m; i++)
        {
            int data;
            cin >> data;
            queueValues.push_back(data);
        }

        vector<int> stackResult;
        for (int i = n - 1; i >= 0; --i)
        {
            stackResult.push_back(stackValues[i]);
        }

        vector<int> queueResult = queueValues;

        if (stackResult == queueResult)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
