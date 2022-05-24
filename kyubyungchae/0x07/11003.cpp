#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    deque<int> dq;

    while(n--) {
        int a;
        cin >> a;
        dq.push_back(a);

        int idx = 0;
        int min_val = 1000000001;
        deque<int>::reverse_iterator iter;
        for(iter = dq.rbegin(); iter != dq.rend(); iter++) {   
            if(idx == l)
                break;
            // cout << *iter << ' ';
            if(*iter < min_val) {
                min_val = *iter;
            }            
            idx++;
        }
        // cout << '\n';
        cout << min_val << ' ';
    }


    return 0;
}
