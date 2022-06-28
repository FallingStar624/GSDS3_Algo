#include <bits/stdc++.h>
using namespace std;
void func(int a,int b,int c);
int board[130][130];
int arr[2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++)
            cin >> board[i][j];
    }
    func(a, 0, 0);
    cout << arr[0]<<'\n'; //하얀
    cout << arr[1];
}
void func(int a,int b,int c)
{
    bool flag1=true; // 행렬에 0 만 있다
    bool flag2=true;
    if (a == 1) {
        arr[board[b][c]]++;
        return;
    }
    for (int i=b;i<b+a;i++)
    {
        for (int j=c;j<c+a;j++)
        {
            if (board[i][j]==1)
            {
                flag1=false;
            }
            else
            {
                flag2=false;
            }

        }
    }
    if (flag1)
    {
        arr[0]++;
    }
    else if (flag2) arr[1]++;
    else {
        func(a / 2, b, c);
        func(a / 2, b, c+a / 2);

        func(a / 2, b+a / 2, c);
        func(a / 2, b+a / 2, c+a / 2);
    }

}