#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, k;
bool visit[100001];
char board[1001][1001];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    queue<pair<int, int>> Q;
    Q.push(make_pair(n, 0));
    while(!Q.empty()) {
        auto curr = Q.front();
        visit[curr.first]=true;
        Q.pop();
        if(curr.first==k) {
            cout << curr.second;
            break;
        }
        if (-1 < curr.first-1 && !visit[curr.first-1]) Q.push(make_pair(curr.first-1, curr.second+1));
        if (curr.first+1 <100001 && !visit[curr.first+1]) Q.push(make_pair(curr.first+1, curr.second+1));
        if (2*curr.first < 100001 && !visit[2*curr.first]) Q.push(make_pair(2*curr.first, curr.second+1));
    }
    return 0;
}
