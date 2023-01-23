#include <iostream>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int inputs[] = {};

    for(int i = 0; i < 3; i++)
        cin >> inputs[i];

    string strnum = to_string(inputs[0] * inputs[1] * inputs[2]);

    int occur[10] = {0};

    for(auto c : strnum) {
        occur[c - '0']++;
    }

    for(int i = 0; i < 10; i++) {
        cout << occur[i] << '\n';
    }

    return 0;
}