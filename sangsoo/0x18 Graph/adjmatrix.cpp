#include <vector>
#include <iostream>
using namespace std;

// Directed graph
int main1(){
    int adj_matrix[10][10] = {};
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
    }
}

// Undirected graph
int main2(){
    int adj_matrix[10][10] = {};
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
}