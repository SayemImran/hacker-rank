#include <bits/stdc++.h>
using namespace std;

class Students {
public:
    string nm;            
    int cls;              
    char s;               
    long long id;        
    int math_marks;       
    int eng_marks;       
};


bool cmp(Students l, Students r) {
    if (l.eng_marks != r.eng_marks) {
        return l.eng_marks > r.eng_marks;  
    }
    if (l.math_marks != r.math_marks) {
        return l.math_marks > r.math_marks; 
    }
    return l.id < r.id;  
}

int main() {
    int n;
    cin >> n;                   
    Students arr[n];             

    for (int i = 0; i < n; i++) {
        cin >> arr[i].nm >> arr[i].cls >> arr[i].s >> arr[i].id >> arr[i].math_marks >> arr[i].eng_marks;
    }

    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i].nm << " " << arr[i].cls << " " << arr[i].s << " " << arr[i].id << " " << arr[i].math_marks << " " << arr[i].eng_marks << endl;
    }

    return 0;
}
