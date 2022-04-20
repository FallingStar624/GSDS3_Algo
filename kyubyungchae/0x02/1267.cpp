#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, t, total_y, total_m;
    cin >> N;
    total_y = 0;
    total_m = 0;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        total_y += ((t / 30) + 1) * 10;
        total_m += ((t / 60) + 1) * 15;
    }
    if (total_y == total_m) 
        cout << "Y M " << total_y;
    else if (total_y < total_m) 
        cout << "Y " << total_y;
    else 
        cout << "M " << total_m;

    return 0;
}