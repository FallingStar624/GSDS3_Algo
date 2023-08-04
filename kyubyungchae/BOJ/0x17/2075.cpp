#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <utility>
#include <queue>

using namespace std;

int arr[1501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<>> pq;
    int n, num;
    cin >> n;

    for(int i = 0; i < n * n; ++i) {
        cin >> num;
        pq.push(num);
        if (n < (int)pq.size()) pq.pop();
    }

    cout << pq.top() << '\n';

    return 0;
}
