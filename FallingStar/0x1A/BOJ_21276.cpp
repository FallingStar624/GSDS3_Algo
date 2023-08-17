#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;

int N, M, K;
string X, Y;
vector<string> names;
map<string, vector<string>> desc;
int degree[1001];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> X;
        names.push_back(X);
    }
    sort(names.begin(), names.end());
    cin >> M;
    for (int i=0 ; i<M; i++) {
        cin >> X >> Y;
        desc[Y].push_back(X);
        auto it = find(names.begin(), names.end(), X);
        int x_idx =  it - names.begin();
        degree[x_idx]++;
    }
    vector<string> res;
    int cnt = 0;
    for (int i=0; i<N; i++) {
        if(degree[i]==0) {
            res.push_back(names[i]);
            cnt ++;
        }
    }
    cout << cnt << '\n';
    for (auto it : res) cout << it << ' ';
    cout << '\n';
    for (auto it : names) {
        cout << it << ' ' << desc[it].size() << ' ';
        sort(desc[it].begin(), desc[it].end());
        for (auto des : desc[it]) {
            cout << des << ' ';
        }
        cout << '\n';
    }

    return 0;
}
