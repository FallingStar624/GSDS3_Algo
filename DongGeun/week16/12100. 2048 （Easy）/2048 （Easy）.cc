#include <bits/stdc++.h>
using namespace std;

int n;
int board[22][22];
int board2[22][22];
int r,q,z,y,x;
int check_block(void);
void return_seq(int i);
void rotate();
void move_board(int a);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >>  board[i][j];
        }
    }
    int mx=0;
    for(int i = 0; i < 1024; i++)
    {
        return_seq(i);
        //cout<<r<<q<<z<<y<<x<<'\n';
        copy(&board[0][0],&board[0][0]+22*22,&board2[0][0]);
        move_board(x);
        move_board(y);
        move_board(z);
        move_board(q);
        move_board(r);

        int block_mx=check_block();
        if (block_mx>mx)  mx=block_mx;

    }
    cout<<mx;

}



int check_block(void)
{
    int res=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (board2[i][j]>res) res=board2[i][j];
    }
    return res;
}
void return_seq(int i)
{//x + 4y + 16z + 64q+ 256r
    r = i/256;
    i-=256*r;

    q = i/64;
    i-=64*q;

    z = i/16;
    i-=16*z;

    y = i/4;
    i-=4*y;

    x = i;

}
void move_board(int a)
{

    while(a--) rotate();
    for(int i = 0; i < n; i++){
        int temp[21] = {}; 
        int idx = 0; 
        for(int j = 0; j < n; j++){
            if(board2[i][j] == 0) continue;
            if(temp[idx] == 0)
                temp[idx] = board2[i][j];
            else if(temp[idx] == board2[i][j]) 
                temp[idx++] *= 2;
            else 
                temp[++idx] = board2[i][j];
        }
        for(int j = 0; j < n; j++) board2[i][j] = temp[j];
    }
}
void rotate(){
    int tmp[21][21];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board2[i][j] = tmp[n-1-j][i];
}
