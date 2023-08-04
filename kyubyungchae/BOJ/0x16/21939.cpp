#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <utility>
#include <string>

using namespace std;

string op;
int N, M, L, P, x;
int probLevel[100002]; // 문제당 난이도
set<int> probByLevel[102]; // 난이도 별 문제


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);   
    cin >> N;

    while(N--) {
        cin >> P >> L;
        probLevel[P] = L;
        probByLevel[L].insert(P);
    }

    cin >> M;
    while(M--) {
        cin >> op;
        if(op == "add") {
            cin >> P >> L;
            probLevel[P] = L;
            probByLevel[L].insert(P);
        } 
        else if(op == "solved") {
            cin >> P;
            probByLevel[probLevel[P]].erase(P);
        } 
        else {
            cin >> x;
            if(x == 1) {
                for(int i = 100; 0 <= i; --i) {
                    if(probByLevel[i].empty())
                        continue;
                    cout << *(prev(probByLevel[i].end())) << '\n';
                    break;
                }
            } else {
                for(int i = 0; i < 101; ++i) {
                    if(probByLevel[i].empty()) continue;
                    cout << *probByLevel[i].begin() << '\n';
                    break;
                }

            }

        }
        
    }

    return 0;
}