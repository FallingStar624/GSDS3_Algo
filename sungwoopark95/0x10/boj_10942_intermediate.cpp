#include <iostream>
using namespace std;

// hint 얻었음 - d[S][E]: S ~ E의 수열이 palindrome인지 아닌지 

int N, M, S, E;
int arr[2010];
int d[2010][2010];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    
    for (int i=1;i<=N;i++) {
        d[i][i] = 1; // S == E이면 palindrome
        if (arr[i-1] == arr[i]) { d[i-1][i] = 1;} // 2개가 서로 연속해서 같으면 palindrome
    }
    
    int dif = 2;
    for (int i=1;i<=N;i++) {
        if (arr[i+dif] == arr[i] && d[i+1][i+dif-1] == 1) { d[i][i+dif] = 1; } // dif=2이면 i+dif-1=i+1로 항상 1
    }
    dif = 3;
    for (int i=1;i<=N;i++) {
        if (arr[i+dif] == arr[i] && d[i+1][i+dif-1] == 1) { d[i][i+dif] = 1; }
    }
    dif = 4;
    for (int i=1;i<=N;i++) {
        if (arr[i+dif] == arr[i] && d[i+1][i+dif-1] == 1) { d[i][i+dif] = 1; }
    }
    
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}