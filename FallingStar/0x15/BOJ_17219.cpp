#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, i;
string address, pw;

int main() {
    cin.tie(0);ios::sync_with_stdio(0);
    unordered_map<string, string> m;
    cin >> N >> M;
    for (i=0; i<N; i++) {
        cin >> address >> pw;
        m[address] = pw;
    }

    for (i=0; i<M; i++) {
        cin >> address;
        cout << m[address] << '\n';
    }

    return 0;
}
