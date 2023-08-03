#include <iostream>
#include <unordered_map>
using namespace std;

int N, M, i, j;
string apparel, category;

int main() {
    cin.tie(0);ios::sync_with_stdio(0);
    unordered_map<string, int> m;
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> M;
        for (j=0; j<M; j++) {
            cin >> apparel >> category;
            m[category]++;
        }
        int ans = 1;
        for (auto it:m) {
            ans*=it.second+1;
        }
        m.clear();
        cout << ans-1 << endl;
    }
    return 0;
}
