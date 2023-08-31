#include <iostream>
#define INF 987654321
#define BND 401
using namespace std;

int n, m, x, y, tmp;
int arr[BND][BND];

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i=0; i<m ;i++) {
        cin >> x >> y >> tmp;
        arr[x][y] = tmp;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n ;i++) {
            for (int j=1; j<=n; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    int ans=INF;
    for (int i=1; i<=n; i++) {
        ans = min(ans, arr[i][i]);
    }
    if (ans < INF) {
        cout << ans;
    } else {
        cout << -1;
    }
    return 0;
}
