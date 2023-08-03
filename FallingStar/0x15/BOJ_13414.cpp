#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int K, L, i;
string tmp;

int main() {
    cin.tie(0);ios::sync_with_stdio(0);
    unordered_map<string, int> m;
    cin >> K >> L;
    int order = 0;
    for (i=0; i<L; i++) {
        cin >> tmp;
        m[tmp] = order;
        order++;
    }
    vector<pair<string, int>> v (m.begin(), m.end());
    sort(v.begin(), v.end(), [](auto &a, auto &b) {return a.second < b.second;});
    int end = min(K, (int)v.size());

    for (i=0; i<end; i++) {
        cout << v[i].first << '\n';
    }

    return 0;
}
