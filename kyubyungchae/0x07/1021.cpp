#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    deque<int> dq;

    for(int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    int ans = 0;
    
    while(M--) {
        int t;
        cin >> t;

        int idx;
        idx = find(dq.begin(), dq.end(), t) - dq.begin();

        while(dq.front() != t) {
            if(idx <= dq.size()/2) {
                dq.push_back(dq.front());
                dq.pop_front();
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }
    cout << ans;
    return 0;
} 