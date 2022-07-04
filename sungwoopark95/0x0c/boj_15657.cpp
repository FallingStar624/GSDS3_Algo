#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int seq[10];

void func(int cur) {
    if (cur == M) {
        for (int i=0;i<M;i++) { cout << arr[i] << " "; }
        cout << "\n";
        return;
    }
    
    for (int i=0;i<N;i++) {
        if (cur >= 1 && arr[cur-1] > seq[i]) { continue; }
        arr[cur] = seq[i];
        func(cur+1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> seq[i];
    }
    sort(seq, seq+N);
    
    func(0);
    
    return 0;
}