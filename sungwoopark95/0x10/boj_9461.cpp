#include <iostream>
using namespace std;

// fibonacci again
// 이러나 저러나 1~5까지는 default로 주어지는 경우를 생각해야 함
int T, N, max_n;
int arr[105]; // N 받아놓는 array
long long fib[105];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> arr[i];
        if (max_n < arr[i]) { max_n = arr[i]; }
    }
    
    fib[1] = 1; fib[2] = 1; fib[3] = 1;
    fib[4] = 2; fib[5] = 2;
    
    for (int i=6;i<=max_n;i++) {
        fib[i] = fib[i-1] + fib[i-1-4];
    }
    
    for (int i=0;i<T;i++) {
        cout << fib[arr[i]] << "\n";
    }
    
    return 0;
}