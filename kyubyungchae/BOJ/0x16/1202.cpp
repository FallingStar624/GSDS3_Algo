#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <utility>

using namespace std;

int n, k;
pair<int, int> jewel[300003]; // price, weight
multiset<int> bag;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);   
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> jewel[i].second >> jewel[i].first;
    }
    sort(jewel, jewel+n);

    for(int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        bag.insert(c);
    }

    long long ans = 0;

    for(int i = n-1; i >= 0; i--) {
        int m, v;
        tie(v, m) = jewel[i];
        auto it = bag.lower_bound(m);
        if(it == bag.end())
            continue;
        ans += v;
        bag.erase(it);
    }
    cout << ans;

    return 0;
}