#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int max = 2 * num;

    for (int i=1;i<num;i++) {
        cout << string(i, '*');
        cout << string(max-(2*i), ' ');
        cout << string(i, '*') << endl;
    }
    cout << string(max, '*') << endl;
    for (int i=num-1;i>0;i--) {
        cout << string(i, '*');
        cout << string(max-(2*i), ' ');
        cout << string(i, '*') << endl;
    }    

    return 0;
}