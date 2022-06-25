#include <iostream>
#include <sstream>
using namespace std;
int k;
int board[64][64];

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
        cout << board[r][c];
        return;
    } else {
        cout << "(";
        recur(r, c, size/2);
        recur(r, c+size/2, size/2);
        recur(r+size/2, c, size/2);
        recur(r+size/2, c+size/2, size/2);
        cout << ")";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for (int i=0; i<k; ++i) {
        string tmp;
        cin >> tmp;
        stringstream ss;
        ss.str(tmp);
        char num;
        int j=0;
        while (ss>>num) {
            board[i][j]=num-48;
            j++;
        }
    }
    recur(0, 0, k);
    return 0;
}
