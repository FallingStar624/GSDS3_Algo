#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int seq[10];
int arr[10];
bool isused[10];

void func(int cur) {
    if (cur == M) {
        for (int i=0;i<M;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i=0;i<N;i++) {
        if (!isused[i]) {
            arr[cur] = seq[i];
            isused[i] = 1;
            func(cur+1);
            isused[i] = 0;
        }
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