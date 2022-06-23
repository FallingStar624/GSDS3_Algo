#include <iostream>
using namespace std;
int k;
int blue=0, white=0;
int board[128][128];

bool check_all(int r, int c, int size) {
    int first = board[r][c];
    for (int i=r; i<r+size; ++i) {
        for (int j=c; j<c+size; ++j) {
            if (first!=board[i][j]) return false;
        }
    }
    return true;
}

void recur(int r, int c, int size) {
    if (check_all(r, c, size)) {
        if (board[r][c]) {
            blue -= size*size;
            blue++;
        } else {
            white -= size*size;
            white++;
        }
    } else {
        recur(r, c, size/2);
        recur(r+size/2, c, size/2);
        recur(r, c+size/2, size/2);
        recur(r+size/2, c+size/2, size/2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for (int i=0; i<k; ++i) {
        for (int j=0; j<k; ++j) {
            int tmp;
            cin >> tmp;
            board[i][j]=tmp;
            if (tmp) {
                blue++;
            } else {
                white++;
            }
        }
    }
    recur(0, 0, k);
    cout << white << endl;
    cout << blue << endl;
    return 0;
}
