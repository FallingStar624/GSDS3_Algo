#include <iostream>
using namespace std;
bool isUsed1[40];
bool isUsed2[40];
bool isUsed3[40];
int cnt=0;
int n;

void back_track(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }
    for (int i=0; i<n; i++) {
        if (isUsed1[i] || isUsed2[i+cur] || isUsed3[cur-i+n-1]) {
            continue;
        }
        isUsed1[i] = true;
        isUsed2[i+cur] = true;
        isUsed3[cur-i+n-1] = true;
        back_track(cur+1);
        isUsed1[i] = false;
        isUsed2[i+cur] = false;
        isUsed3[cur-i+n-1] = false;
    }
}


int main() {
    cin >> n;
    back_track(0);
    cout << cnt;
    return 0;
}
