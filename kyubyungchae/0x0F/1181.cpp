#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string words[20001];

bool comp(string a, string b) {
    if(a.size() != b.size()) {
        return a.size() < b.size();
    }

    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    sort(words, words + n, comp);

    string tmp = words[0];
    cout << tmp << '\n';
    for(int i = 1; i < n; i++) {
        if(tmp != words[i])
            cout << words[i] << '\n';
        tmp = words[i];
    }

    return 0;
}