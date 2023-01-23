#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string inputs[1000001];
long long outputs[1000001];

long long flip(string s) {
    string tmp = "";

    for(int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        if(tmp == "" && c == '0')
            continue;
        tmp += c;
    }

    if(tmp == "")
        return (long long)0;

    return stoll(tmp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> inputs[i];
    }

    for(int i = 0; i < n; i++) {
        outputs[i] = flip(inputs[i]);
    }

    sort(outputs, outputs + n);

    for(int i = 0; i < n; i++) {
        cout << outputs[i] << '\n';
    }

    return 0;
}