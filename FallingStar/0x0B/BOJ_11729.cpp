#include <iostream>
#include <cmath>
using namespace std;
int n;

void hannoi(int disk, int from, int detour, int to) {
    if (disk==1) {
        cout << from << " " << to << "\n";
        return;
    }
    hannoi (disk-1, from, to, detour);
    cout << from << " " << to << "\n";
    hannoi (disk-1, detour, from, to);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    int cnt = pow(2, n) -1;
    cout << cnt << endl;
    hannoi(n, 1, 2, 3);
    return 0;
}
