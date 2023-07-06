#include <bits/stdc++.h>
using namespace std;

char board[6200][6200];

void func(int n, int x, int y){
    if (n == 3){
        board[x][y+1] = '*';
        // board[x+1][y] = '*';
        // board[x+1][y+1] = '*';
        // board[x+1][y+2] = '*';
    }
    else if (n == 6){
        board[x][y+2] = '*';
        board[x+1][y+1] = '*';
        board[x+1][y+3] = '*';
        board[x+2][y] = '*';
        board[x+2][y+1] = '*';
        board[x+2][y+2] = '*';
        board[x+2][y+3] = '*';
        board[x+2][y+4] = '*';
    }
    else {
        func(n/2, x, y+n/4);
        func(n/2, x+n/4, y);
        func(n/2, x+n/4, y+n/2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2*n; j++)
            board[i][j] = ' ';

    func(2*n, 0, 0);
    for (int i = 0; i < n; i++)
        cout << board[i] << '\n';

    return 0;
}