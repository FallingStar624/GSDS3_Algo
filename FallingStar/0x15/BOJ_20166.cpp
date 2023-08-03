#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
char arr[10][10];
string tmp;
int dr[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
map<string, int> counter;

void dfs(int r, int c, string trace) {
    if (trace.length() > 5)  return;
    if (counter.find(trace)!=counter.end()) {
        counter[trace]+=1;
    }
    int nr, nc;
    for (int i=0; i<8; i++) {
        nr = r + dr[i];
        nc = c + dc[i];
        if (nr >= N) nr = 0;
        if (nr <= -1) nr = (N-1);
        if (nc >= M) nc = 0;
        if (nc <= -1) nc = (M-1);
        string next_trace = trace + arr[nr][nc];
        dfs(nr, nc, next_trace);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        cin >> tmp;
        for (int j=0; j<M; j++){
            arr[i][j] = tmp[j];
        }
    }
    for (int i=0; i<K; i++) {
        cin >> tmp;
        counter[tmp] = 0;
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            dfs(i, j,string(1,arr[i][j]));
        }
    }
    for (auto it: counter)  {
        cout << it.second << endl;
    }
    return 0;
}
