#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> ropes;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        ropes.push_back(tmp);
    }
    sort(ropes.begin(), ropes.end(), greater<int>());
    int W = 0;
    for (int i=0; i<ropes.size(); i++) {
        W = max(W, (i+1)*ropes[i]);
    }
    cout << W;
    return 0;
}
