#include <bits/stdc++.h>
using namespace std;
void func(int a,int b,int c);
char board[6600][6600];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int a;
    cin>>a;
    func(a,0,0);
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<a;j++) {
            cout<<board[i][j];
        }
        cout<<'\n';
    }
}
void func(int a,int b,int c)
{
    if (a==3)
    {
        for (int i=b;i<b+a;i++)
        {
            for (int j=c;j<c+a;j++)
            {

                board[i][j]='*';
            }
        }
        board[b+1][c+1]=' ';
        return;
    }
    func(a/3,b,c);
    func(a/3,b,c+a/3);
    func(a/3,b,c+2*a/3);

    func(a/3,b+a/3,c);
    //func(a/3,b+a/3,c+a/3);
    for (int i=b+a/3;i<b+a;i++)
    {
        for (int j=c+a/3;j<c+a;j++)
        {

            board[i][j]=' ';
        }
    }
    func(a/3,b+a/3,c+2*a/3);

    func(a/3,b+2*a/3,c);
    func(a/3,b+2*a/3,c+a/3);
    func(a/3,b+2*a/3,c+2*a/3);




}
