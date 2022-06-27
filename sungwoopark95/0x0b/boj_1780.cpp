#include <bits/stdc++.h>
using namespace std;
#define MAX 2187

int N;
int nums[3];
int paper[MAX][MAX];

bool check(int N, int x, int y) {
    for (int i=x;i<x+N;i++) {
        for (int j=y;j<y+N;j++) {
            if (paper[x][y] != paper[i][j]) { return false; }
        }
    }
    return true;
}

void find(int N, int x, int y) {
    if (check(N, x, y)) {
        int num = paper[x][y];
        nums[num+1]++;
        return;
    }
    int n = N / 3;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            find(n, x+i*n, y+j*n);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> paper[i][j];
        }
    }

    find(N, 0, 0);
    
    for (int k=0;k<3;k++) {
        cout << nums[k] << "\n";
    }
    
    return 0;
}