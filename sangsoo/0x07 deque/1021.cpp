#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);
    int ans = 0;
    while (m--){
        int t;
        cin >> t;
        int idx = find(dq.begin(), dq.end(), t) - dq.begin(); // idx : t가 있는 위치, find is in <algorithm>
        // for (int i = 0; i < dq.size(); i++){
        //     if (dq[i] == t) {idx = i; break;}
        // } 
        while (dq.front() != t){
            if (idx < dq.size()-idx){ // 왼쪽으로 rotate할지(idx), 오른쪽으로 rotate할지 (dq.size()-idx)
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }
    cout << ans;
}

