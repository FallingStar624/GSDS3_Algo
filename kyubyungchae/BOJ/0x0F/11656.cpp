#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string S;
string backs[1001];

void genBack(string s) {

    string tmp = "";
    for(int i = s.size() - 1; i >= 0; i--) {
        tmp = s[i] + tmp;
        backs[i] = tmp;
        // cout << tmp << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    genBack(S);
    sort(backs, backs + S.size());

    for(int i = 0; i < S.size(); i++) {
        cout << backs[i] << '\n';
    }
    return 0;
}