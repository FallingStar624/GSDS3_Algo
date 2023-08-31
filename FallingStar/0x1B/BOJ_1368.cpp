#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans=0;
int parent[302];
int cost[301][301];

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if (a==b) return true;
    else return false;
}

class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this -> node[0] = a;
        this -> node[1] = b;
        this -> distance = distance;
    }
    bool operator < (Edge &edge) {
        return this->distance < edge.distance;
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<Edge> edge;
    int tmp;
    for (int i=0; i<N; i++) {
        cin >> tmp;
        edge.push_back(Edge(i, 300, tmp));
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            edge.push_back(Edge(i, j, cost[i][j]));
        }
    }
    sort(edge.begin(), edge.end());
    for (int i=0; i<N; i++) parent[i]=i;
    parent[300] = 300;
    for (int i=0; i<edge.size(); i++){
        int front = edge[i].node[0];
        int end = edge[i].node[1];
        int dist = edge[i].distance;
        if(!findParent(front, end)) {
            ans += dist;
            unionParent(front, end);
        }
    }
    cout << ans;

    return 0;
}
