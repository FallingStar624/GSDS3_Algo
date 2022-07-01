#include <bits/stdc++.h>
using namespace std;
#define MAX 128

int N;
int nums[2];
int paper[MAX][MAX];

bool check(int n, int x, int y) {
    for (int i=x;i<x+n;++i) {
        for (int j=y;j<y+n;++j) {
            if (paper[i][j] != paper[x][y]) { return false; }
        }
    }
    return true;
}

void find(int N, int x, int y) {
    if (check(N, x, y)) { 
        nums[paper[x][y]]++; 
        return;
    }
    int n = N / 2;
    for (int i=0;i<2;++i) {
        for (int j=0;j<2;++j) {
            find(n, x+n*i, y+n*j);
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
    
    cout << nums[0] << "\n";
    cout << nums[1] << "\n";
    
    return 0;
}