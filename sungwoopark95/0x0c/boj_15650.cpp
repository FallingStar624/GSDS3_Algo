#include <iostream>
using namespace std;

int N, M;
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
    
    for (int i=1;i<=N;i++) {
        if(!isused[i-1]) {
            if (cur >= 1 && arr[cur-1] > i) { continue; }
            arr[cur] = i;
            isused[i-1] = 1;
            func(cur+1);
            isused[i-1] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    func(0);
    
    return 0;
}