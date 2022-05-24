#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

// 이번 문제에서는 무엇이 필요할까? BFS 
// why? -> distance를 구해야 하기 때문

class Node{
public:
    int val;
    int color;
    int dist;
    int x;
    int y;
    vector<Node*> adj;
    Node(int v, int i, int j){
        val = v;
        color = 0;
        dist = INT_MAX;
        adj = {};
        x = i;
        y = j;
    };
};

int main(){
    int n, m; cin >> n >> m;
    Node* graph[n][m];


    // initialize graph
    char input;
    int input_num;
    Node* newnode;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> input;
            input_num = (int)input - 48;
            newnode = new Node(input_num, i, j);
            graph[i][j] = newnode;
        }
    }

    // set adj nodes
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    int new_i;
    int new_j;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(graph[i][j]->val == 1){ // 현재 도착한 노드가 1인경우에만
                for(int d=0; d<4; ++d){
                    new_i = i+dy[d];
                    new_j = j+dx[d];
                    if(new_i >=0 && new_i <=n-1 && new_j >=0 && new_j <= m-1){ // 인접노드의 coord가 영역 안에 있는 경우만
                        if(graph[new_i][new_j]->val == 1){ // 인접노드가 1인 경우에만 원래 노드의 adj에 push
                            graph[i][j]->adj.push_back(graph[new_i][new_j]);
                        }
                    }
                }
            }
        }
    }

    // bfs
    Node* start = graph[0][0];

    start->color = 1; // gray
    start->dist = 1;

    queue<Node*> que;
    que.push(start);

    Node* curnode;
    Node* adjnode;
    while(!que.empty()){
        curnode = que.front();
        que.pop();
        for(int i=0; i< curnode->adj.size(); ++i){
            adjnode = curnode->adj[i];
            if(adjnode->color == 0){ // white 인경우
                adjnode->color = 1; // gray로 변경
                adjnode->dist = curnode->dist +1; // 부모노드의 dist +1
                que.push(adjnode);
            }
        }
        curnode->color = 2; // black
    }

    cout << graph[n-1][m-1]->dist;



}