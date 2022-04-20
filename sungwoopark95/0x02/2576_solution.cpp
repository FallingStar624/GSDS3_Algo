#include <iostream>
using namespace std;

// 이거 왜 틀렸다고 나오죠;;
int main() {
    int sum = 0;
    int num; int smallest;

    cin >> num;
    if (num % 2 == 1) {
        sum += num;
        smallest = num;
    }
    for (int round=0;round<6;round++) {
        cin >> num;
        if (num % 2 == 1) {
            sum += num;
            if (smallest > num) {
                smallest = num;
            }
        }
    }

    if (sum == 0) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
        cout << smallest << endl;
    }
    return 0;
}