#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <utility>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;

    while(n--) {
        int x;
        cin >> x;

        if(x == 0) {
            if(pq.empty()) {
                cout << "0\n";
            }
            else {
                int num = pq.top(); pq.pop();
                cout << num << '\n';
            }
        }
        else {
            pq.push(x);
        }        
    }

    return 0;
}