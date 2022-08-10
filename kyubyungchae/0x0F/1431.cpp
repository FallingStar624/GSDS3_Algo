#include <iostream>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

int n;
string inputs[51];

bool comp(string a, string b) {
    if(a.size() != b.size()) {
        return a.size() < b.size();
    }
    int sum1 = 0;
    int sum2 = 0;
    for(char c1 : a) {
        if(c1 < 'A')
            sum1 += c1 - '0';
    }
    for(char c2 : b) {
        if(c2 < 'A')
            sum2 += c2 - '0';
    }
    if(sum1 != sum2) {
        return sum1 < sum2;
    }
    return a < b;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> inputs[i];
    }

    sort(inputs, inputs + n, comp);

    for(int i = 0; i < n; i++) {
        cout << inputs[i] << '\n';
    }

    return 0;
}