#include <iostream>
using namespace std;

int main() {
    int spot1, spot2, spot3;
    int prize; int max;

    cin >> spot1 >> spot2 >> spot3;

    int arr[3] = {spot1, spot2, spot3};
    max = spot1;
    for (int i=1;i<3;i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    if ((spot1 == spot2) & (spot2 == spot3)) {
        prize = 10000 + (spot1 * 1000);
    } else if ((spot1 == spot2) || (spot1 == spot3)) {
        prize = 1000 + (spot1 * 100);
    } else if (spot2 == spot3) {
        prize = 1000 + (spot2 * 100);
    } else {
        prize = max * 100;
    }

    cout << prize << endl;
    return 0;
}