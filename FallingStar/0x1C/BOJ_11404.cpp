#include <iostream>
#define INF 987654321
using namespace std;

int n, m, x, y, tmp;
int arr[101][101];

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i=0; i<m ;i++) {
        cin >> x >> y >> tmp;
        if (tmp < arr[x][y]) arr[x][y] = tmp;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n ;i++) {
            for (int j=1; j<=n; j++) {
                if (i==j) continue;
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            tmp = arr[i][j];
            if (tmp < 987654321) {
                cout << tmp << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
