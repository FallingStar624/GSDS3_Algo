#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[32002];
int indegree[32002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
    vector<int> tmp;
    for(int i = 1; i <= n ; i++){
        if(indegree[i] == 0){
            pq.push(i);
        }
    }

    vector<int> result;
    while(!pq.empty()){
        int cur = pq.top(); pq.pop();
        result.push_back(cur); vector<int> tmp2;
        for(auto nxt : adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt] == 0) pq.push(nxt);
        }

    }
    for(auto idx : result) cout << idx << ' ';
}
