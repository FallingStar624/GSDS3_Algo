#include <vector>
#include <iostream>
using namespace std;

// Directed graph
int main1(){
    vector<int> adj[10];
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
}

// Undirected graph
int main2(){
    vector<int> adj[10];
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}