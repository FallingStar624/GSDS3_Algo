#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    deque <int> dq;
    vector <int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for (int i = 0 ; i < N; i++){
        while(!dq.empty() && dq.front() <= i-L)
            dq.pop_front();
        while (!dq.empty() && arr[dq.back()] > arr[i])
            dq.pop_back();
        dq.push_back(i);
        cout << arr[dq.front()] << ' ';
    }
}