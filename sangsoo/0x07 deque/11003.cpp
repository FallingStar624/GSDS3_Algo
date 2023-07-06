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
    for (int i = 0; i < N; i++){
        // Remove elements outside the current window
        while (!dq.empty() && dq.front() <= i-L)
            dq.pop_front();
        // Remove elements in the window which are larger than the cuurent element
        // as they are useless (we are interested in minimum value)
        while (!dq.empty() && arr[dq.back()] > arr[i])
            dq.pop_back();
        dq.push_back(i);
        cout << arr[dq.front()] << ' ';
    }
}
