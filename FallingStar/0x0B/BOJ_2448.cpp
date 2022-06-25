#include <iostream>
using namespace std;
int k;
bool board[3072][6144];


void recur(int r, int c, int size) {
    if (r>=3072) return;
    if (c>=6144) return;
    if (size==3) {
        board[r][c] = true;
        board[r+1][c-1] = true;
        board[r+1][c+1] = true;
        for (int i=0; i<5; ++i) {
            board[r+2][c-2+i] = true;
        }
    } else {
        recur(r, c, size/2);
        recur(r+size/2, c-size/2,size/2);
        recur(r+size/2, c+size/2, size/2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    recur(0, k, 2*k);
    for (int i=0; i<k; ++i) {
        for (int j=1; j<2*k; ++j) {
            if (board[i][j]) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << "\n";
    }
    return 0;
}
