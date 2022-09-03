#include <iostream>
#include <queue>
#include <tuple>
#define mytype tuple<int, int>
using namespace std;
int N;
struct cmp{
    bool operator()(mytype a, mytype b) {
        if (get<0>(a)!=get<0>(b)) {
            return get<0>(a) > get<0>(b);
        } else {
            return get<1>(a) < get<1>(b);
        }
    }
};
priority_queue<mytype, vector<mytype>, cmp> pq;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        int start, end;
        cin >> start >> end;
        mytype tmp = make_tuple(start, end);
        pq.push(tmp);
    }
    int cnt=1;
    int curr_time = get<0>(pq.top());
    pq.pop();
    while (!pq.empty()) {
        mytype curr = pq.top();
        int ts = get<0>(curr);
        int te = get<1>(curr);
        if (ts >= curr_time) {
            cnt++;
            curr_time = te;
        }
        pq.pop();
    }
    cout << cnt;
    return 0;
}
