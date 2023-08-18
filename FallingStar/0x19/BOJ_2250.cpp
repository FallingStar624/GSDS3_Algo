#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, p, l ,r, mx_depth=0, ans=0, ans_depth;
int parent[10001];
int leftChild[10001];
int rightChild[10001];
int res[10001];
vector<int> depth[10001];

void dfs(int num, int d) {
    if (num==-1) return;
    depth[d].push_back(num);
    mx_depth = max(mx_depth, d);
    dfs(leftChild[num], d+1);
    dfs(rightChild[num], d+1);
}

int bfs(int num) {
    if (num == -1) return 0;
    int cnt = 0;
    queue<int> q;
    q.push(num);
    while (!q.empty()) {
        int curr = q.front();
        cnt++;
        q.pop();
        if (leftChild[curr] > 0) q.push(leftChild[curr]);
        if (rightChild[curr] > 0) q.push(rightChild[curr]);
    }
    return cnt;
}

int find_left(int num) {
    int res = 0;
    int curr = num;
    if (leftChild[curr]) res += bfs(leftChild[curr]);
    while (curr>0) {
        int curr_p = parent[curr];
        if (!curr_p) return res;
        if (curr == rightChild[curr_p]) {
            res += bfs(leftChild[curr_p]) + 1;
        }
        curr = curr_p;
    }
    return res;
}

int find_right(int num) {
    int res = 0;
    int curr = num;
    if (rightChild[curr]) res += bfs(rightChild[curr]);
    while (curr>0) {
        int curr_p = parent[curr];
        if (!curr_p) return res;
        if (curr == leftChild[curr_p]) {
            res += bfs(rightChild[curr_p]) + 1;
        }
        curr = curr_p;
    }
    return res;
}
int find_root(int num) {
    int root = num;
    while (true) {
        int root_p = parent[root];
        if (!root_p) break;
        root = root_p;
    }
    return root;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> p >> l >> r;
        leftChild[p] = l; rightChild[p] = r;
        parent[l] = p; parent[r] = p;
    }
    // get depth
    int root = find_root(1);
    dfs(root, 1);
    for (int i=1; i<=mx_depth; i++) {
        int mostleft, mostright;
        mostleft = find_left(depth[i].front());
        mostright = find_right(depth[i].back());
        int length = N - mostleft - mostright;
        if (length > ans) {
            ans = length;
            ans_depth = i;
        }
    }
    cout << ans_depth << ' ' << ans;
    return 0;
}

