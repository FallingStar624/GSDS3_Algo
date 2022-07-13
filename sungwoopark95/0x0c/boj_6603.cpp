#include <iostream>
#include <algorithm>
using namespace std;

int K;
int arr[20];
int seq[20];
bool isused[20];

void func(int cur) {
    if (cur == 6) {
        for (int i=0;i<6;i++) { cout << arr[i] << " "; }
        cout << "\n";
        return;
    }
    
    for (int i=0;i<K;i++) {
        if (!isused[i]) {
            if (cur>=1 && arr[cur-1] > seq[i]) { continue; }
            arr[cur] = seq[i];
            isused[i] = 1;
            func(cur+1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    while(1) {
        cin >> K;
        if (K == 0) { return 0; }
        
        for (int i=0;i<K;i++) {
            cin >> seq[i];
        }
        
        sort(seq, seq+K);
        func(0);
        cout << "\n";
    }
    
    return 0;
}