#include <iostream>
#define INF 987654321
#define BND 101
using namespace std;

int n, m, r, x, y, tmp;
int arr[BND][BND];
int items[BND];

int main() {
    cin >> n >> m >> r;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i=1; i<=n; i++) cin >> items[i];
    for (int i=0; i<r ;i++) {
        cin >> x >> y >> tmp;
        arr[x][y] = tmp;
        arr[y][x] = tmp;
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
    int ans=0;
    for (int i=1; i<=n; i++) {
        int tmp = items[i];
        for (int j=1; j<=n; j++) {
            if (i==j) continue;
            if (arr[i][j]<=m) tmp += items[j];
        }
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
