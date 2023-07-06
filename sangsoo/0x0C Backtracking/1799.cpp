#include <bits/stdc++.h>
#define max(a, b) a > b ? a : b
using namespace std;

int arr1[20]; // i+j  0 ~ 2*n-2
int arr2[20]; // i-j+n-1 0 ~ 2*n-2
int board[10][10]; 
int ans[2];
int n; //, cnt;
void func(int x, int y, int cnt, int color){
    if (y>= n){
        x++;
        if (y%2==0) y = 1;
        else y =0;
    }
    if(x>=n){
        ans[color] = max(ans[color], cnt);
        return;
    }
    if(board[x][y] && !arr1[x+y] && !arr2[x-y+n-1]){
        arr1[x+y] = arr2[x-y+n-1] = 1;
        func(x, y+2, cnt+1, color);
        arr1[x+y] = arr2[x-y+n-1] = 0;
    }
    func(x, y+2, cnt, color);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    func(0, 0, 0, 0);
    func(0, 1, 0, 1);
    cout << ans[0] + ans[1];
}