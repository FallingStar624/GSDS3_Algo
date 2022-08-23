#include <iostream>
#include <algorithm>
using namespace std;
    // 7 -> 3, 8            d[0][0]
    //   7-3 -> 8, 1 (o)   
    //   7-8 -> 1, 0 (o)
    
    //       7-3-8 -> 2,7 (o)
    //       7-3-1 -> 7,4

    //       7-8-1 -> 7,4 (o)
    //       7-8-0 -> 4,4

    //              7-3-8-2 -> 4,5   (best : 7+3+8+2+5 = 25)
    //              7-3-8-7 -> 5,2   (best : 7+3+8+7+5 = 30) v
    //              7-3-1-7 -> 5,2   (best : 7+3+1+7+5 = 23)
    //              7-3-1-4 -> 2,6   (best : 7+3+1+4+6 = 21)

    //              7-8-1-7 -> 5,2   (best : 7+8+1+7+5 = 28) v 
    //              7-8-1-4 -> 2,6   (best : 7+8+1+4+6 = 26)
    //              7-8-0-4 -> 2,6   (best : 7+8+0+4+6 = 25)
    //              7-8-0-4 -> 6,5   (best : 7+8+0+4+6 = 25)
int n;
int board[501][501];
int d  [501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // init
    cin >>n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            cin >>board[i][j];
        }
    }   

    // base
    d[1][1] = board[1][1];
    // -> 1
    d[2][1] = d[1][1] + board[2][1];
    // -> 1 + 5 = 6
    d[2][2] = d[1][1] + board[2][2];
    // -> 1 + 0  = 1

    // dp
    int opt1;
    int opt2;
    for(int i=3; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            if(j==1){
                d[i][j] = d[i-1][j] + board[i][j];
            }
            else if(j==i){
                d[i][j] = d[i-1][j-1] + board[i][j];
            }
            else{
                opt1 = d[i-1][j-1] + board[i][j];
                opt2 = d[i-1][j] + board[i][j];
                d[i][j] = max(opt1, opt2);
            }
        }
    }

    // for(int i=1; i<=n; ++i){
    //     for(int j=1; j<=i; ++j){
    //         cout << d[i][j]<<" ";
    //     }
    //     cout <<"\n";
    // }

    // return 0;

    int res = -1;
    for(int j=1; j<=n; ++j)
        if(d[n][j] > res) res = d[n][j];
    cout << res;
}