#include <queue>
#include <iostream>
using namespace std;

int N, x;
priority_queue<int> l; // 최대 힙
priority_queue<int, vector<int>, greater<int>> r; //최소 힙

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i=1; i<N+1; i++) {
        cin >> x;
        if (i==1) {
            l.push(x);
        } else if (i==2) {
            if (x > l.top())  r.push(x);
            else {
                r.push(l.top());
                l.pop();
                l.push(x);
            }
        } else {
            l.push(x);
            if (l.top()>r.top()) {
                int tmp = r.top();
                r.pop();
                r.push(l.top());
                l.pop();
                l.push(tmp);
            }

            if (l.size() > r.size()+1) {
                r.push(l.top());
                l.pop();
            }
            if (l.size() < r.size()) {
                l.push(r.top());
                r.pop();
            }

        }

        cout << l.top() << '\n';
    }
    return 0;
}

