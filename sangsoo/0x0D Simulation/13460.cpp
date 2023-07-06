// fail
// https://junbastick.tistory.com/37


#include <bits/stdc++.h>
using namespace std;

struct step{
    int Rx, Ry;
    int Bx, By;
    int Count;
};

char board[11][11];
bool visited[11][11][11][11];
int N, M;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void move(int& rx, int& ry, int& distance, int& i){
    while (board[rx+dx[i]][ry+dy[i]] != '#' && board[rx][ry] != 'O'){
        rx += dx[i];
        ry += dy[i];
        distance += 1;
    }
}

void BFS(int Rx, int Ry, int Bx, int By){
    queue<step> q;
    q.push({Rx, Ry, Bx, By, 0});
    visited[Rx][Ry][Bx][By] = true;
    while(!q.empty()){
        int rx = q.front().Rx;
        int ry = q.front().Ry;
        int bx = q.front().Bx;
        int by = q.front().By;
        int count = q.front().Count;
        q.pop();
        if (count >= 10) break;
        for (int i = 0; i < 4; i++){
            int nrx = rx, nry=ry, nbx = bx, nby = by;
            int rc = 0, bc = 0, ncount = count+1;
            move(nrx, nry, rc, i);
            move(nbx, nby, bc, i);
            if(board[nbx][nby] == 'O') continue;
            if(board[nrx][nry] == 'O'){
                cout << ncount;
                return;
            }
            if(nrx == nbx && nry == nby){
                if(rc > bc) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dy[i];
            }
            if (visited[nrx][nry][nbx][nby]) continue;
            visited[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, ncount});
        }
    }
    cout << -1;
}

void Answer(){
    cin >> N >> M;
    int Rx = 0, Ry = 0, Bx = 0, By = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R') Rx = i, Ry = j;
            else if (board[i][j] == 'B') Bx = i, By = j;
        }
    }
    BFS(Rx, Ry, Bx, By);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    Answer();
    return 0;
}