#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
    int n, temp; cin >> n;
    long long result;
    stack<int> S;
    pair<int, stack<int>> arr[n];
    for (int i=0; i<n; i++) {
        cin >> temp;
        arr[i].first = temp;
        for (int j=0; j<i; j++) {
            if (arr[j].second.empty()) {
                arr[j].second.push(temp);
            } else if (arr[j].second.top() > arr[j].first) {
                continue;
            } else if (arr[j].second.top() <= temp) {
                arr[j].second.push(temp);
            }
        }
    }
    result = 0;
    for (int i=0; i<n; i++) {
        result += arr[i].second.size();
    }
    cout << result;
    return 0;
}
