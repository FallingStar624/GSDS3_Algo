#include <iostream>
#include <stack>
using namespace std;

int main() {
    unsigned int k, temp, result; cin >> k;
    stack<int> S;
    while (k--) {
        cin >> temp;
        if (temp) {
            S.push(temp);
        } else S.pop();
    }
    result=0;
    while (!S.empty()) {
        result += S.top();
        S.pop();
    }
    cout << result;
    return 0;
}
