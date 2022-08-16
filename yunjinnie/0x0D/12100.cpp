// 2048 on N by N (<=20)
// 한 번 이동: u/d/r/l
// 충돌 시 sum (한 번 이동에서 이미 합쳐진 블록 추가 x)
// 이동마다 블록 추가 없음
// 빈 칸: 0, 이외의 값: 블록 (2<=, <=1024, 2^n), default -> given input
// 최대 5번 이동해서 얻을 수 있는 가장 큰 블록

// brute force, simulation, back tracking
// u/d/r/l, dfs, main
#include <bits/stdc++.h>
using namespace std;

int N;
//int board[21][21];
//int copied[21][21];
int ans;

struct B{
    int board[21][21];

    void rotate(){
        int tmp[21][21];
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                tmp[j][N-i-1] = board[i][j]; 
            }
        }
        //swap() N=N
        for (int r=0; r<N; r++){
            for (int c=0; c<N; c++){
                board[r][c] = tmp[r][c];
            }
        }
    }

    void shift(){
        //queue<int> q;
        /*
        switch(dir){
            // up
            case 1:
            // down
            case 2:
            // right
            case 3:
            // left
            case 4:
        }
        */
        //int tmp[21][21];
        vector<int> v;
        for (int j=1; j<=N; j++){
            for (int i=1; i>=N; i++){
                if(board[i][j]==1) {
                    v.push_back(board[i][j]);
                }
                board[i][j]=0;
            }
            for (int k=0, idx=1; k<v.size(); k++, idx++){
                if(k+1<v.size() && v[k]==v[k+1]){
                    board[idx][k]=v[k++]*2; // 2->4, 4->8
                }
                else board[idx][j]=v[k];
            }
            v.clear();
        }
        /*
        for (int r=0; r<N; r++){
                for (int c=0; c<N; c++){
                    board[r][c] = tmp[r][c];
                }
            }*/

    }

    int plus(){
        int res = 0;
        for (int i=0;i<N;i++){
            for(int j=0; j<N;j++){
                if (board[i][j]>res)
                    res = board[i][j]; // 합치기
            }
        }
        return res;
    }

};

// 중복순열

void dfs(B map, int cnt){
    if (cnt==5) {
/*        for (int i = 0; i<N; i++){
            for (int j = 0; j<N; j++){
                board[i][j] = copied[i][j];
            }
        } */
        ans = max(ans, map.plus());
        return ;
    }

    for (int i=0; i<4; i++){
        //shift(copied[21][21]);
        B next = map;
        next.shift();
        dfs(next, cnt+1); // cnt++ : print error
        //B.shift(board[21][21]);
        map.rotate();
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    B b;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin>>b.board[i][j];
        }
    }
    dfs(b, 0);
    cout<<ans<<'\n';
    return 0;

}

// https://chrisyslpgmr.tistory.com/3
// https://velog.io/@statco19/boj-12100
// https://9967han.tistory.com/16