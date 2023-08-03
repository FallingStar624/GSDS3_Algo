#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q, curr=0, cmd, x;
bool tmp;
set<int> A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (int i=0; i<N; i++) {
        cin >> tmp;
        if (tmp) {
            A.insert(i);
        }
    }
    while (Q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            if (A.find(x-1)==A.end()) {
                A.insert(x-1);
            } else {
                A.erase(x-1);
            }
        } else if (cmd == 2) {
            cin >> x;
            curr += x;
            curr %= N;
        } else if (cmd == 3) {
            if (A.empty()) cout << -1 << '\n';
            else {
                auto it = A.lower_bound(curr);
                if (it!=A.end()) {
                    cout << *it - curr << '\n';
                } else {
                    cout << N-curr+*A.begin() << '\n';
                }
            }
        }
    }
    return 0;
}
