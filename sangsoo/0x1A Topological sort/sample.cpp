#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10];
int deg[10];
int n;


queue<int> q;
vector<int> result;
int main(){
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    if(result.size() != n)
        cout << "Cycle exists";
    else{
        for(auto x : result) cout << x << ' ';
    }
}