#include <bits/stdc++.h>
using namespace std;
int board[64][64];
void func(int a,int b,int c);


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int a;
    cin>>a;
    for (int i = 0; i < a; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < a; j++)
            board[i][j] = str[j] - '0';
    }
    func(a,0,0);
}
void func(int a,int b,int c)
{
    bool flag1=true; // 행렬에 0만 있다
    bool flag2=true;
    if (a == 1) {
        cout << board[b][c];
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
            else flag2=false;
        }
    }
    if (flag2)
    {
        cout<<"1";
    }
    else if (flag1) cout<<"0";
    else {
        cout << "(";
        func(a / 2, b, c);
        func(a / 2, b, c+a / 2);
        func(a / 2, b+a / 2, c);
        func(a / 2, b+a / 2, c+a / 2);
        cout << ")";
    }

}
