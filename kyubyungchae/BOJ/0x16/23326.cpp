#include <set>
#include <iostream>
#include <algorithm>

using namespace std;


int q, i, x;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q, q;
    int hold = 1;
    set<int> place;
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i) {
        cin >> q;
        if(q) place.insert(i);
    }

    while(Q--) {
        cin >> q;

        switch (q)
        {
        case 1:
            cin >> q;
            if(place.find(q) != place.end())
                place.erase(q);
            else
                place.insert(q);
            break;
        
        case 2:
            cin >> q;
            hold = (hold + q - 1) % N + 1;
            break;
        
        case 3:
            if(place.empty())
                cout << -1 << '\n';
            else {
                auto it = place.lower_bound(hold);
                if(it != place.end())
                    cout << *it - hold << '\n';
                else
                    cout << N - hold + *place.begin() << '\n';

            }

        }
        

    }

    return 0;
}