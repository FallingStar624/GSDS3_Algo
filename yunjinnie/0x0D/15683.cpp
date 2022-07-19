// 감시카메라 1: 한 방향, 2 : 일렬 두 방향, 3 : 직교 두 방향, 4 : 세 방향, 5 :  네 방향 + 6 : 벽
// 감시 가능 영역 : #, 빈칸 : 0
// N by M : 사무실 크기
// 그 다음 N*M만큼의 matrix 형태 input
// 사각 지대 최소 크기 출력

// brute force, dfs with u/d/r/l, backtracking (N, M (3))

#include <bits/stdc++.h>
using namespace std;

int area = INT_MAX;
int n, m;
int room[9][9];
int newroom[9][9];
vector<pair<int, int>> cctv;

void copy(int room[9][9], int newroom[9][9]){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            newroom[i][j] = room[i][j];
        }
    }
}

void up(int room[9][9], int r, int c){
    // row만 변경
    int i=r+1;
    while (i<n){
        if (room[i][c]==0)
            room[i][c]=-1;
        else if (room[i][c]==6)
            break;
        i++;
    }
}

void down(int room[9][9], int r, int c){
    // row만 변경
    int i=r-1;
    while (i>=0){
        if (room[i][c]==0)
            room[i][c]=-1;
        else if (room[i][c]==6)
            break;
        i--;
    }
}

void right(int room[9][9], int r, int c){
    // col만 변경
    int i=c+1;
    while (i<m){
        if (room[r][i]==0)
            room[r][i]=-1;
        else if (room[r][i]==6)
            break;
        i++;
    }
}

void left(int room[9][9], int r, int c){
    // col만 변경
    int i=c-1;
    while (i>=0){
        if (room[r][i]==0)
            room[r][i]=-1;
        else if (room[r][i]==6)
            break;
        i--;
    }
}

void dfs(int room[9][9], int cnt) { // int
    copy(room, newroom);

    if(cnt == cctv.size()) {
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(room[i][j] == 0)
                    ans++;
            }
        }
        area = min(area, ans);
        return;
    }
    else{
        int x = cctv[cnt].first; //row
        int y = cctv[cnt].second; //col
        switch (room[x][y]){
            case 1:{
                up(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                down(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);
                
                right(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);
                
                left(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                break;
            }

            case 2:{
                up(newroom, x, y);
                down(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);
                
                right(newroom, x, y);
                left(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                break;
            }

            case 3:{
                up(newroom, x, y);
                right(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                right(newroom, x, y);
                down(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);
                
                down(newroom, x, y);
                left(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                left(newroom, x, y);
                up(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                break;
            }

            case 4: {
                up(newroom, x, y);
                down(newroom, x, y);
                right(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                up(newroom, x, y);
                down(newroom, x, y);
                left(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                right(newroom, x, y);
                left(newroom, x, y);
                down(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                right(newroom, x, y);
                left(newroom, x, y);
                up(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);

                break;
            }

            case 5: {
                up(newroom, x, y);
                down(newroom, x, y);
                right(newroom, x, y);
                left(newroom, x, y);
                dfs(newroom, cnt+1);
                copy(room, newroom);
                break;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);

    cin>>n>>m;
    for (int row = 0; row<n; row++){
        for (int col = 0; col<m; col++){
            cin>>room[row][col];
            if (room[row][col]>0 && room[row][col]<6){
                cctv.push_back({row, col});
            }
            //switch (room[row][col])
        }
    }

    dfs(room, 0);

    cout<<area<<'\n';
    return 0;
}

// https://dingcoding.tistory.com/m/138