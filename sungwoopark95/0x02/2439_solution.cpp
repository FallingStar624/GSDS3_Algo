#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    for (int i=1;i<=num;i++) {
        cout << string(num-i, ' ') << string(i, '*') << endl; // string repetition
    }

    return 0;
}