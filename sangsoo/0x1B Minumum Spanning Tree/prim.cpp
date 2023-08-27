#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;


int main(){
    int v, e; // {비용, 정점 번호}

    vector<pair<int, int>> adj[100005];
    // chk[i] : i번째 정점이 최소 신장 트리에 속해 있는가?
    bool chk[100005];
    int cnt = 0; // 현재 선택된 간선의 수
    // tuple<int, int, int> : {비용, 정점 1, 정점2}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq; // 최소 힙


    for(auto nxt : adj[1]) pq.push({nxt.first, 1, nxt.second});
    while(cnt < v-1){
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        cout << cost << ' ' << a << ' ' << b << '\n';
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]){
            if(!chk[nxt.second]) pq.push({nxt.first, b, nxt.second});
        }
    }
 
}