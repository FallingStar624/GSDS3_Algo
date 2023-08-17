#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> adj[1002]; // 가수 마다 인접 방향저장
int indegree[1002]; // 가수마다 indegree
vector<int> adj_helper[102]; // pd마다 가수 순서 임시 저장해주는 벡터
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    for(int i = 0; i < m; i++){ // pd들
        int num_s; // pd가 담당하는 가수 수
        cin >> num_s;
        for(int j = 0; j <num_s; j++){
            int s; // 가수
            cin >> s;
            adj_helper[i].push_back(s);
            if (j != 0){
                adj[adj_helper[i][j-1]].push_back(adj_helper[i][j]); // 이전 것이 먼저 다음 것이 다음
                indegree[adj_helper[i][j]]++;
            }
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> result;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for(auto nxt : adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt]==0) q.push(nxt);
        }
    }
    if(result.size() == n){
        for(auto e : result)
            cout << e << '\n';
    }
    else
        cout << 0;

}