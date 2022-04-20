#include <iostream>

using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int tmp, total;
        cin >> tmp;
        total += tmp;
        cin >> tmp;
        total += tmp;
        cout << total << '\n';
        total = 0;
    }

    return 0;
}

