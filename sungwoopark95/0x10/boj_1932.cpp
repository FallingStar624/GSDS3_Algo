#include <iostream>
#include <algorithm>
using namespace std;

int n; // 삼각형의 크기
int triangle[505][505];
int sum[505][505]; // 합의 최댓값을 담는 array

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            cin >> triangle[i][j];
        }
    }

    sum[1][1] = triangle[1][1];

    for (int i=2;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + triangle[i][j];
        }
    }
    
    int max = -1;    
    for (int i=1;i<=n;i++) {
        if (max < sum[n][i]) { max = sum[n][i]; }
    }
    cout << max << "\n";
    
    return 0;
}