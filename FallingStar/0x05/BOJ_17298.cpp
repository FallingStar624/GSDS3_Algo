#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


int main() {
    int n, tmp; cin >> n;
    vector<int> V(n, -1);
    stack<pair<int, int>> S;
    for (int i=0; i<n; i++){
        cin >> tmp;
        if(S.empty()) {
            S.push(make_pair(tmp, i));
        } else {
            if (S.top().first < tmp) {
                while (S.top().first < tmp) {
                    V[S.top().second] = tmp;
                    S.pop();
                    if (S.empty()) break;
                }
                S.push(make_pair(tmp, i));
            } else {
                S.push(make_pair(tmp, i));
            }
        }
    }
    for (int x : V) cout << x << " ";


    return 0;
}
