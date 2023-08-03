#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    while (N--) {
        cin >> x;
        if (x==0) {
            if (q.empty()) cout << 0 << '\n';
            else {
            cout << q.top() << '\n';
            q.pop();
            }
        } else {
            q.push(x);
        }
    }
    return 0;
}

