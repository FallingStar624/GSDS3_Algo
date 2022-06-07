#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int K;
        cin >> K;
        multiset<int> ms;
        for (int k = 0; k < K; ++k) {
            char op;
            int num;
            cin >> op >> num;
            if (op == 'I') ms.insert(num);
            else if (ms.empty()) continue;
            else if (num == 1) ms.erase(prev(ms.end()));
            else ms.erase(ms.begin());
        }
        if (ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << " " << *ms.begin() << '\n';
    }


    return 0;
}