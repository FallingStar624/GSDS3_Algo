#include <iostream>
using namespace std;
#define MAX 2*3072+1

char board[MAX][MAX];

void star(int N, int x, int y) {
    if (N == 3) {
        board[x][y] = '*';
        board[x+1][y-1] = '*';
        board[x+1][y+1] = '*';
        for (int i=-2;i<=2;i++) {
            board[x+2][y+i] = '*';
        }
        return;
    }
    int n = N / 2;
    star(n, x, y);
    star(n, x+n, y-n);
    star(n, x+n, y+n);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    cin >> N;

    star(N, 0, N-1);
    for (int i=0;i<N;i++) {
        for (int j=0;j<2*N-1;j++) {
            if (board[i][j] == '*') { cout << '*'; }
            else { cout << ' '; }
        }
        cout << "\n";
    }

    return 0;
}