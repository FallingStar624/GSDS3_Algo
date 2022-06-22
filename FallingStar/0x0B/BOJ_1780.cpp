#include <iostream>
using namespace std;
int n, A, B, C; // A: 1, B: 0, C: -1
int arr[2188][2188];

bool check_same(int r, int c, int size) {
    int tmp = arr[r][c];
    for (int i=r; i<r+size; i++) {
        for (int j=c; j<c+size; j++) {
            if (arr[i][j]!=tmp) return false;
        }
    }
    return true;
}

void recur(int r, int c, int size) {
    if (size==1) return;
    if (check_same(r, c, size)) {
        if (arr[r][c]==1) {
            A -= size*size-1;
        } else if (arr[r][c]==0) {
            B -= size*size;
            B++;
        } else {
            C -= size*size-1;
        }
    } else {
        recur(r, c, size/3);
        recur(r+size/3, c, size/3);
        recur(r+2*size/3, c, size/3);
        recur(r, c+size/3, size/3);
        recur(r+size/3, c+size/3, size/3);
        recur(r+2*size/3, c+size/3, size/3);
        recur(r, c+2*size/3, size/3);
        recur(r+size/3, c+2*size/3, size/3);
        recur(r+2*size/3, c+2*size/3, size/3);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==1) {
                A++;
            } else if (arr[i][j]==0) {
                B++;
            } else {
                C++;
            }
        }
    }
    recur(0,0,n);
    cout << C << endl;
    cout << B << endl;
    cout << A << endl;
    return 0;
}
