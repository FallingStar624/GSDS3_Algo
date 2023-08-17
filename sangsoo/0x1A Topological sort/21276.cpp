#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m;
map<string, int> mm; // 순서대로 정렬해주려고 이렇게 넣음
unordered_map<int, string> rm; // reverse map;
vector<int> adj[1002];
int indegree[1002];
vector<string> des_arr[1002]; // 자식들을 담는 vector
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        rm[i] = name;
        mm[name] = i;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        string des, anc; // descendant, ancestor;
        cin >> des >> anc;
        adj[mm[anc]].push_back(mm[des]);
        indegree[mm[des]]++;
    }
    queue<int> q;
    vector<string> father;
    for(int i = 0; i < n; i++){
        if (indegree[i] == 0){
            father.push_back(rm[i]);
            q.push(i);
        }
    }
    sort(father.begin(), father.end());
    cout << father.size() << '\n';
    for(auto f : father) cout << f << ' ';
    cout << '\n';
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            indegree[nxt]--;
            if (indegree[nxt]==0){
                q.push(nxt);
                des_arr[cur].push_back(rm[nxt]); 
            }
        }
    }
    for(auto it : mm){
        cout << it.first << ' ';
        vector<string> v = des_arr[mm[it.first]];
        sort(v.begin(), v.end());
        cout << v.size() << ' ';
        for(auto nn : v) cout << nn << ' ';
        cout << '\n';
    }
}