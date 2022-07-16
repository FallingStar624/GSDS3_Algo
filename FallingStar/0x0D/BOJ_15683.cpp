// TBD
/*
4 6
2 6 0 3 0 2
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 6 1
*/

#include <iostream>
using namespace std;
int room[8][8];
int d[4] = {0, 1, 2, 3};
// 0: 동 1:서 2:남 3:북
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1 , 0 , 0};
int c3[4] = {2, 3, 1, 0};
int n, m, ans;

int watch(int r, int c, int dir, bool install) {
    int cnt=0;
    r+=dr[dir];
    c+=dc[dir];
    while (-1<r && r<n && -1<c && c<m) {
        if (room[r][c]==0) {
            cnt++;
            if (install) {
                room[r][c]=-1;
            }
            r+=dr[dir];
            c+=dc[dir];
        } else if (room[r][c]==-1) {
            r+=dr[dir];
            c+=dc[dir];
        } else if (room[r][c]<6) {
            r+=dr[dir];
            c+=dc[dir];
        } else {
            break;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> room[i][j];
        }
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            int cur = room[i][j];
            if (cur==0|| cur==-1|| cur==6) {
                continue;
            }
            if (cur==1) {
                int mx_cnt=0, mx_dir=0;
                for (int k=0; k<4; k++) {
                    int tmp_cnt;
                    tmp_cnt = watch(i,j,k, false);
                    if (tmp_cnt > mx_cnt) {
                        mx_cnt = tmp_cnt;
                        mx_dir = k;
                    }
                }
                watch(i, j, mx_dir, true);
            } else if (cur==2) {
                int mx_cnt=0, mx_dir=0;
                for (int k=0; k<2; k++) {
                    int tmp_cnt=0;
                    tmp_cnt += watch(i, j, 2*k, false);
                    tmp_cnt += watch(i, j , 2*k+1, false);
                    if (tmp_cnt > mx_cnt) {
                        mx_cnt = tmp_cnt;
                        mx_dir = k;
                    }
                }
                watch(i,j,2*mx_dir, true);
                watch(i, j, 2*mx_dir+1, true);
            } else if (cur==3) {
                int mx_cnt=0, mx_dir=0;
                for (int k=0; k<4; k++) {
                    int tmp_cnt = watch(i,j,k, false);
                    tmp_cnt += watch(i, j, c3[k], false);
                    if (tmp_cnt > mx_cnt) {
                        mx_cnt = tmp_cnt;
                        mx_dir = k;
                    }
                }
                watch(i, j, mx_dir, true);
                watch(i, j, c3[mx_dir], true);
            } else if (cur==4) {
                int mx_cnt=0, mx_dir=0;
                for (int k=0; k<4; k++) {
                    int tmp_cnt=0;
                    for (int l=k+1; l<k+4; l++) {
                        tmp_cnt += watch(i, j, l%4, false);
                    }
                    if (tmp_cnt > mx_cnt) {
                        mx_cnt = tmp_cnt;
                        mx_dir = k;
                    }
                }
                for (int k=0; k<4; k++) {
                    if (k==mx_dir) continue;
                    watch(i, j ,k, true);
                }
            } else if (cur==5) {
                for (int k=0; k<4; k++) {
                    watch(i, j, k, true);
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << room[i][j] << " ";
            if (room[i][j]==0) ans++;
        }
        cout << "\n";
    }
    cout << ans;
    return 0;
}

