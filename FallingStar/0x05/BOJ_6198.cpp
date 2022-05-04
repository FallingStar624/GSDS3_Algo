#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, tmp; cin >> n;
    long long result = 0;
    stack<long long> S;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        while (!S.empty()) {
            if(S.top() > tmp) break;
            S.pop();
        }
        result += (long long)S.size();
        S.push(tmp);
    }
    cout << result ;
    return 0;
}
