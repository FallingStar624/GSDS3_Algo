#include <iostream>
#include <deque>

using namespace std;

deque<int> deq;
deque<int> check;
int n, m, i, tmp, cnt;

int main() {
    cin >> n >> m;
    for (i=0; i<m; i++) {
        cin >> tmp;
        check.push_back(tmp);
    }
    for (i=0; i<n; i++) {
        deq.push_back(i+1);
    }
    cnt = 0;
    while (!check.empty()) {
        if (deq.front()==check.front()) {
            tmp = check.front();
            check.pop_front();
            deq.pop_front();
            if (check.empty()) break;
        } else {
            for (i=0;i<deq.size();i++){
                if (deq[i]==check.front()) tmp = i;
            }
            if (tmp > (deq.size()-tmp)) {
                cnt += deq.size()-tmp;
                i = deq.size()-tmp;
                while (i--) {
                    tmp = deq.back();
                    deq.pop_back();
                    deq.push_front(tmp);
                }
            } else {
                cnt += tmp;
                i = tmp;
                while (i--) {
                    tmp = deq.front();
                    deq.pop_front();
                    deq.push_back(tmp);
                }
            }
        }
    }
    cout << cnt;
    return 0;
}

