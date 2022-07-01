#include <bits/stdc++.h>
using namespace std;
#define MAX 128

int N;
int video[MAX][MAX];

bool check(int n, int x, int y) {
    for (int i=x;i<x+n;i++) {
        for (int j=y;j<y+n;j++) {
            if (video[i][j] != video[x][y]) { return false; }
        }
    }
    return true;
}

void find(int N, int x, int y) {
    int cnt = 0;
    if (check(N, x, y)) {
        for (int i=x;i<x+N;i++) {
            for (int j=y;j<y+N;j++) {
                cnt += video[i][j];
            }
        }
        if (N == 1) {
            cout << cnt;
        } else {
            cout << cnt / (1<<N);
        }
        return;
    }
    int n = N / 2;
    cout << "(";
    for (int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            find(n, x+n*i, y+n*j);
        }
    }
    cout << ")";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        string str;
        cin >> str;
        for (int j=0;j<str.length();j++) {
            video[i][j] = str[j] - 48;
        }
    }
    
    find(N, 0, 0);
    
    return 0;
}