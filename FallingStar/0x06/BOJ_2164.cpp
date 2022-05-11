#include <iostream>
#include <queue>
using namespace std;

int n, i, tmp;
queue<int> Q;

int main() {
    cin >> n;
    for (i=0; i<n; i++) Q.push(i+1);
    while(Q.size()>1) {
        Q.pop();
        tmp = Q.front();
        Q.pop();
        Q.push(tmp);
    }
    cout << Q.front() << endl;
    return 0;
}
