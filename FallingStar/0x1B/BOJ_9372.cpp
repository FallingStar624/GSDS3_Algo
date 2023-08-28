#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, a, b;
int parent[1001];

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
    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> N >> M;
        vector<Edge> edge;
        for (int i=0; i<M; i++) {
            cin >> a >> b;
        }
        cout << N-1 << endl;
    }
    return 0;
}
