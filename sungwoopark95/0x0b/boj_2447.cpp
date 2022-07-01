#include <iostream>
using namespace std;
#define MAX 2300

char board[MAX][MAX];

void star(int N, int x, int y) {
    if (N == 1) { 
        board[x][y] = '*'; 
        return;
    }
    int n = N / 3;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (i == 1 && j == 1) {
                continue;
            } else {
                star(n, x+i*n, y+j*n);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            board[i][j] = ' ';
        }
    }
    
    star(N, 0, 0);
    for (int i=0;i<N;i++) {
        cout << board[i] << '\n';
    }
    
    return 0;
}