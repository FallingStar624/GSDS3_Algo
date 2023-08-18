#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

int N, M, K=0;
string X, Y;
vector<string> names;
unordered_map<string, vector<string>> desc;
int degree[1001];

int get_idx(string s) {
    auto it = find(names.begin(), names.end(), s);
    int x_idx =  it - names.begin();
    return  x_idx;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // get input
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
        int x_idx = get_idx(X);
        degree[x_idx]++;
    }
    // find roots
    vector<string> res;
    for (int i=0; i<N; i++) {
        if(degree[i]==0) {
            res.push_back(names[i]);
            K ++;
        }
    }
    // sort predecessor
    for (auto i : names) {
        vector<string> tmp;
        for (auto j : desc[i]) {
            if (degree[get_idx(j)]-degree[get_idx(i)] == 1) {
                tmp.push_back(j);
            }
        }
        desc[i] = tmp;
    }
    // output
    cout << K << '\n';
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

