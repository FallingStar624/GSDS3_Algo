#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans=0;
int board1[20][20];
int board2[20][20]; // 초기 상태 저장
int dr[4] = {0, 0, -1, 1}; // 오른쪽, 왼쪽, 위, 아래
int dc[4] = {1, -1, 0, 0};

void reset_board() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n ;j++) {
            board1[i][j] = board2[i][j];
        }
    }
}

int find_max() {
   int maximum = 0;
   for (int i=0; i<n; i++) {
       for (int j=0; j<n; j++) {
           maximum = max(maximum, board1[i][j]);
       }
   }
    return maximum;
}

void transform(int dir, int r, int c) {
    int nr=r+dr[dir], nc=c+dc[dir];
    if (nr<0 || nc<0 || nr>=n || nc>=n) {
        return;
    } else {
        //
        if (board1[r][c] == board1[nr][nc]) {
            board1[nr][nc] *=2;
            board1[r][c] = 0;
        } else if (board1[nr][nc]==0) {
            board1[nr][nc] = board1[r][c];
            board1[r][c] = 0;
        } else {
            return;
        }
    }
}

void slide(int dir) {
    if (dir==0) { // 오른쪽
        for (int c=n-1; c>-1; c--) {
            for (int r=0; r<n; r++) {
                transform(dir, r, c);
            }
        }
    } else if (dir==1) { // 왼쪽
        for (int c=0; c<n; c++) {
            for (int r=0; r<n; r++) {
                transform(dir, r, c);
            }
        }
    } else if (dir==2) { // 위
        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                transform(dir, r, c);
            }
        }
    } else { // 아래
        for (int r=n-1; r>-1; r--) {
            for (int c=0; c<n; c++) {
                transform(dir, r, c);
            }
        }
    }

}

void back_track(string seq) {
    if (seq.size()==5) {
        reset_board();
        for (char c: seq) {
            slide(c-'0');
        }
        int cur_max = find_max();
        ans = max(ans, cur_max);
        return;
    } else {
        for (int i=0; i<4; i++) {
            back_track(seq + to_string(i));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int tmp;
            cin >> tmp;
            board1[i][j] = tmp;
            board2[i][j] = tmp;
        }
    }
    back_track("");
    cout << ans;
    return 0;
}
