#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Num {
    int pos;
    int value;
    Num(int a, int b) : pos(a), value(b) {}
};

// min-heap
struct cmp {
    bool operator()(Num a, Num b) {
        return a.value>b.value;
    }
};

int n, l, curr;
priority_queue< Num, vector<Num>, cmp> Q;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for (int i=0; i<n; i++) {
        cin >> curr;
        Q.push(Num(i, curr));

        // Q 길이 유지 => 범위를 벗어나는 숫자 제거
        while (!Q.empty() && Q.top().pos <= i-l) {
            Q.pop();
        }
        cout << Q.top().value << " ";
    }
    return 0;
}

