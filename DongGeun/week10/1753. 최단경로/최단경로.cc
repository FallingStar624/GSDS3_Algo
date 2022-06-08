#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int V,E,src;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >>V>>E>>src;
    int result[20001];
    fill(result,result+V+1,3000001);
    result[src]=0;
    vector<pair<int,int>> adj[20002];
    while(E--)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        adj[a].push_back({cost,b});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({result[src],src});
    while(!pq.empty())
    {
        auto a = pq.top();
        int distance=a.X;
        int ver=a.Y;
        pq.pop();
        if (distance!=result[ver]) continue;
        for (auto adj_pair : adj[ver])
        {
            if (result[ver]+adj_pair.X>=result[adj_pair.Y]) continue;
            else
            {
                result[adj_pair.Y]=result[ver]+adj_pair.X;
                pq.push({result[adj_pair.Y],adj_pair.Y});
            }
        }
    }
    for (int i=1;i<=V;i++)
    {
        if (result[i]==3000001) cout<<"INF\n";
        else cout<<result[i]<<'\n';
    }
}