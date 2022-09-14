#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N=0;
    cin >> N;
    while (N>1) {
        int div=2;
        bool flag = true;
        while (flag) {
            if ((N%div)==0) {
                N/=div;
                flag = false;
                cout << div << "\n";
            } else {
                div++;
            }
        }
    }
    return 0;
}
