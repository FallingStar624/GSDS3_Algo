#include <iostream>
using namespace std;
int k;
bool board[2187][2187];

void check_true(int r, int c, int size) {
    for (int i=r; i<r+size; ++i) {
        for (int j=c; j<c+size; ++j) {
            board[i][j]=true;
        }
    }
}

void recur(int r, int c, int size) {
    if (size==1) {
        return;
    } else {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if (i==1 && j==1) {
                    check_true(r+(size/3)*i, c+(size/3)*j, size/3);
                } else {
                    recur(r+(size/3)*i, c+(size/3)*j, size/3);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    recur(0, 0, k);
    for (int i=0; i<k; ++i) {
        for (int j=0; j<k; ++j) {
            if (board[i][j]) {
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        cout << "\n";
    }
    return 0;
}
