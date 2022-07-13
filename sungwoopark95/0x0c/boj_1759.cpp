#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[20];
char seq[20];
bool isused[20];

void func(int cur) {
    if (cur == L) {
        int vowelsum = 0;
        for (int i=0;i<L;i++) {
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') { vowelsum++; }
        }
        
        if (vowelsum == 0 || L-vowelsum < 2) { return; }
        
        for (int i=0;i<L;i++) {
            cout << arr[i];
        }
        cout << "\n";
        return;
    }
    
    for (int i=0;i<C;i++) {
        if (!isused[i]) {
            if (cur >= 1 && arr[cur-1] > seq[i]) { continue; }
            char alphabet = seq[i];
            arr[cur] = alphabet;
            isused[i] = 1;
            func(cur+1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> L >> C;
    for (int i=0;i<C;i++) {
        cin >> seq[i];
    }
    
    sort(seq, seq+C);
    func(0);
    
    return 0;
}