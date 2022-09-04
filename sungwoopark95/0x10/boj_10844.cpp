#include <iostream>
#define MAX 1000000000
using namespace std;

int N;
long long arr[12][105];
long long sum;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    
    // initialization
    arr[0][1] = 0;
    for (int i=1;i<10;i++) { // i denotes a row
        arr[i][1] = 1;
    }
    
    // DP
    for (int j=2;j<=N;j++) { // j denotes a column
        for (int i=0;i<10;i++) {
            if (i == 0) { arr[i][j] = arr[i+1][j-1]; }
            else if (i == 9) { arr[i][j] = arr[i-1][j-1]; }
            else { arr[i][j] = (arr[i-1][j-1] + arr[i+1][j-1]); }
            arr[i][j] %= MAX;
        }
    }

    for (int i=0;i<10;i++) {
        sum += arr[i][N];
    }
    
    cout << sum % MAX << "\n";
    
    return 0;
}