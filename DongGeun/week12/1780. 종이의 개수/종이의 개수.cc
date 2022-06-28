#include <bits/stdc++.h>
using namespace std;
void func(int a,int b,int c);
int board[3100][3100];
int arr[3];
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
    for (int i = 0; i < 3; i++) {
        cout << arr[i];
        cout << '\n';
    }
}
void func(int a,int b,int c)
{
    bool flag1=true; // 행렬에 -1 만 있다
    bool flag2=true;
    bool flag3=true;// 행렬에 1 만 있다
    if (a == 1) {
        arr[board[b][c]+1]++;
        return;
    }
    for (int i=b;i<b+a;i++)
    {
        for (int j=c;j<c+a;j++)
        {
            if (board[i][j]==-1)
            {
                flag2=false;
                flag3=false;
            }
            else if (board[i][j]==0)
            {
                flag1=false;
                flag3=false;
            }
            else
            {
                flag1=false;
                flag2=false;
            }
        }
    }
    if (flag1)
    {
        arr[0]++;
    }
    else if (flag2) arr[1]++;
    else if (flag3) arr[2]++;
    else {
        func(a / 3, b, c);
        func(a / 3, b, c+a / 3);
        func(a / 3, b, c+2*a / 3);

        func(a / 3, b+a / 3, c);
        func(a / 3, b+a / 3, c+a / 3);
        func(a / 3, b+a / 3, c+2*a / 3);

        func(a / 3, b+2*a / 3, c);
        func(a / 3, b+2*a / 3, c+a / 3);
        func(a / 3, b+2*a / 3, c+2*a / 3);



    }

}