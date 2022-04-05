#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    for (int i=0;i<num;i++) {
        cout << string(i, ' ') << string(num-i, '*') << endl;
    }

    return 0;
}