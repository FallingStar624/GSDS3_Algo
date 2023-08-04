#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        multiset<int> ms;

        while(k--) {
            char com;
            cin >> com;
            if(com == 'D') {
                int q;
                cin >> q;
                if(ms.empty())
                    continue;
                if(q == 1)
                    ms.erase(prev(ms.end()));
                else
                    ms.erase(ms.begin());
            }
            else {
                int q;
                cin >> q;
                ms.insert(q);
            }
        }
        if(ms.empty())
            cout << "EMPTY\n";
        else {
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}