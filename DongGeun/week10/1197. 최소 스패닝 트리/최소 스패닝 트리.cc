#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int K,N,M;
vector <pair<int,int>> adj[10005];
bool chk[10005];
int cnt,answer;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >>K>>N;
    for (int i=0;i<N;i++)
    {
        int a,b,cost;
        cin >>a>>b>>cost;
        adj[a].push_back({cost,b});
        adj[b].push_back({cost,a});
    }
    chk[1]=1;
    for (auto x:adj[1]) pq.push({x.X,1,x.Y});
    while(cnt<K-1)
    {
        int cost, a, b;
        tie(cost, a,b)=pq.top();pq.pop();
        if (chk[b]) continue;
        answer+=cost;
        chk[b]=1;
        cnt++;
        for (auto nxt:adj[b])
        {
            if (!chk[nxt.Y]) pq.push({nxt.X,b,nxt.Y});
        }
    }
    cout<<answer;

}