#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int N,K;
int board[200000];
bool vis[200000];
int result[200000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> N >>K;
    board[N]=1;
    vis[N]=1;
    queue<int> Q;
    Q.push(N);
    int num;
    while (!Q.empty())
    {
        int cur = Q.front();
        if (cur==K) break;
        num =result[cur];
        num++;
        Q.pop();
        //cout<<"pop\n";
        for(int nxt : {cur-1, cur+1, 2*cur})
        {
            if (nxt<0||nxt>100000)continue;
            if (vis[nxt])continue;
            vis[nxt]=1;
            result[nxt]=num;
            Q.push(nxt);
        }
    }
    cout<<result[K];

}