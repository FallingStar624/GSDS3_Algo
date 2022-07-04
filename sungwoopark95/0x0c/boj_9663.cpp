#include <iostream>
using namespace std;

bool isused1[40]; // hash array to check whether the space in y-axis direction is already occupied or not
bool isused2[40]; // check whether the space in right-upward diagonal direction is occupied or not
bool isused3[40]; // check whether the space in right-downward diagonal direction is occupied or not
int cnt = 0;
int n;

void func(int cur) {
    // cur: x-coordinate of the queen in the current state
    if (cur == n) {
        cnt++;
        return;
    }
    for (int i=0;i<n;i++) { // i: y-coordinate
        // if spaces in y-axis direction and each diagonal direction are occupied
        if (isused1[i] || isused2[i+cur] || isused3[cur-i+n-1]) { continue; }
        isused1[i] = 1;
        isused2[i+cur] = 1;
        isused3[cur-i+n-1] = 1;
        func(cur+1);
        isused1[i] = 0;
        isused2[i+cur] = 0;
        isused3[cur-i+n-1] = 0;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    func(0);
    cout << cnt;
    
    return 0;
}