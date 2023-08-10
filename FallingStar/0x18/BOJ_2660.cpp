#include <iostream>
#define INF 987654321
using namespace std;

int n, tmp, x, y;
int arr[51][51];
int res[51];

void initializer() {
    cin >> n;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            arr[i][j] = INF;
            if (i==j) arr[i][j] = 0;
        }
    }

    while (true) {
        cin >> x >> y;
        if (x==-1) break;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
}
void floyd() {
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n ;i++) {
            for (int j=1; j<=n; j++) {
                if (i==j) continue;
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}
void collector() {
    tmp = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1;j<=n;j++) {
            tmp = max(tmp, arr[i][j]);
        }
        res[i] = tmp;
        tmp = 0;
    }
    x = INF;
    for (int i=1; i<=n; i++) {
        x = min(res[i], x);
    }
}
void printer() {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (res[i] == x) cnt ++;
    }
    cout << x << " " << cnt << endl;
    for (int i=1; i<=n ;i++) {
        if (res[i] == x) cout << i << " ";
    }
}

int main() {
    initializer();
    floyd();
    collector();
    printer();

    return 0;
}

