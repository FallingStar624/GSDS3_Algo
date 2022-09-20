#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int M, N, cnt=0;

bool checkNum(int num) {
    bool flag = true;
    if (num==1) return false;
    if (num==2) return true;
    int root = ceil(sqrt(num));
    for (int i=2; i<=root; i++) {
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
    cin >> M >> N;
    for (int i=M; i<=N; i++) {
        if (checkNum(i)) {
            cout << i << "\n";
        }
    }
    return 0;
}
