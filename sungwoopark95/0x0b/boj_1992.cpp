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
    if (check(N, x, y)) {
        if (N == 1) {
            cout << video[x][y];
        } else {
            if (video[x][y]) { cout << 1;}
            else { cout << 0; }
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