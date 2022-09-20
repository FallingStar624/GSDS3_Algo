#include <iostream>
#include <algorithm>
using namespace std;
int N, cnt=0;

bool checkNum(int num) {
    bool flag = true;
    if (num==1) return false;
    for (int i=2; i<num; i++) {
        if (num%i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        if (checkNum(tmp)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
