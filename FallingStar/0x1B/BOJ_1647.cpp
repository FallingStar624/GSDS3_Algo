#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, a, b, c;
long long ans=0;
int parent[100001];

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

bool findParent(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if (x==y) return true;
    else return false;
}

class Edge {
public:
    int node[2];
    int distance;
    Edge(int x, int y, int distance) {
        this -> node[0] = x;
        this -> node[1] = y;
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
    cin >> N >> M;
    vector<Edge> edge;
    vector<Edge> usedEdge;
    for (int i=0; i<M; i++) {
        cin >> a >> b >> c;
        edge.push_back(Edge(a, b, c));
    }
    sort(edge.begin(), edge.end());
    for (int i=0; i<N; i++) parent[i]=i;
    for (int i=0; i<edge.size(); i++){
        int front = edge[i].node[0];
        int end = edge[i].node[1];
        int dist = edge[i].distance;
        if(!findParent(front, end)) {
            ans += dist;
            unionParent(front, end);
            usedEdge.push_back(edge[i]);
        }
    }
    int maxCost = 0;
    for (auto e : usedEdge) {
        maxCost = max(e.distance, maxCost);
    }

    cout << ans-maxCost;
    return 0;
}
