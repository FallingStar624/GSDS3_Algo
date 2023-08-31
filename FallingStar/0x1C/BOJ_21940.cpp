#include <iostream>
#include <vector>
#define INF 987654321
#define BND 201
using namespace std;

int n, m, x, y, tmp;
int arr[BND][BND];
vector<int> friends;
vector<int> ans;

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
    for (int i=0; i<m ;i++) {
        cin >> x >> y >> tmp;
        arr[x][y] = tmp;
    }
    cin >> x;
    for (int i=0; i<x; i++) {
        cin >> tmp;
        friends.push_back(tmp);
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
    int min_val = 987654321;
    ans.push_back(INF);
    for (int i=1; i<=n; i++) {
        int tmp=0;
        for (auto fr : friends) {
            tmp = max(tmp, arr[fr][i]+arr[i][fr]);
        }
        min_val = min(min_val, tmp);
        ans.push_back(tmp);
    }
    for (int i=1; i<=n; i++) {
        if (ans[i] == min_val) cout << i << " ";
    }
    return 0;
}
