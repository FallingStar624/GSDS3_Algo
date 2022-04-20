#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int num; 
    int smallest = 100;

    for (int round=0;round<7;round++) {
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