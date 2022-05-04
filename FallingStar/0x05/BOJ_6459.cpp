#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    long long tmp, width=0, result=0;
    stack<long long> S;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        if (S.empty()) {
            S.push(tmp);
            width++;
        } else {
            if (S.top()<=tmp) {
                width++;
            } else {
                result = max(S.top()*width, result);
                S.pop();
                S.push(tmp);
                width = 1;
            }
        }
        cout << S.top() << " " << width << endl;
    }
    cout << result;
    return 0;
}
