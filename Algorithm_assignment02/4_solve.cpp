#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> height(n);  // long long for large values
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    
    long long max1 = -1, max2 = -1;
    int max1Index = -1, max2Index = -1;

    for (int i = 0; i < n; i++) {
        if (height[i] > max1) {
            max2 = max1;
            max2Index = max1Index;
            max1 = height[i];
            max1Index = i;
        } else if (height[i] > max2) {
            max2 = height[i];
            max2Index = i;
        }
    }

   
    cout << min(max1Index, max2Index) << " " << max(max1Index, max2Index) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
