#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> browser_history;
    string site;
    while (true)
    {
        cin >> site;
        cin.ignore();
        if (site == "end")
        {
            break;
        }
        browser_history.push_back(site);
    }
    vector<string> cpyFromList(browser_history.begin(), browser_history.end());
    int q;
    int current_pos = 0;
    cin >> q;

    while (q--)
    {
        string cmd, trgt;
        cin >> cmd;

        if (cmd == "visit")
        {
            cin >> trgt;
            cin.ignore();
            auto it = find(cpyFromList.begin(), cpyFromList.end(), trgt);
            if (it != cpyFromList.end())
            {
                current_pos = it - cpyFromList.begin();
                cout << cpyFromList[current_pos] << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (cmd == "next")
        {
            if (current_pos + 1 < cpyFromList.size())
            {
                current_pos++;
                cout << cpyFromList[current_pos] << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (cmd == "prev")
        {
            if (current_pos - 1 >= 0)
            {
                current_pos--;
                cout << cpyFromList[current_pos] << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }
    return 0;
}