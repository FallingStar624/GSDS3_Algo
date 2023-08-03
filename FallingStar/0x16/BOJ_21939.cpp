#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int N, P, L, M, x, y;
string cmd;
int byNumber[100002];
set<int> byLevel[1000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--) {
        cin >> P >> L;
        byNumber[P] = L;
        byLevel[L].insert(P);
    }
    cin >> M;
    while (M--) {
        cin >> cmd;
        if (cmd=="recommend") {
            cin >> x;
            if (x==1) {
                for (int i=100; i>=0; i--) {
                    if (byLevel[i].empty()) continue;
                    cout << *(prev(byLevel[i].end())) << endl;
                    break;
                }
            } else {
                for (int i=0; i<101; i++) {
                    if (byLevel[i].empty()) continue;
                    cout << *byLevel[i].begin() << endl;
                    break;
                }
            }
        } else if (cmd == "add") {
            cin >> x >> y;
            byNumber[x] = y;
            byLevel[y].insert(x);
        } else if (cmd == "solved") {
            cin >> x;
            byLevel[byNumber[x]].erase(x);
        }
    }
    return 0;
}
