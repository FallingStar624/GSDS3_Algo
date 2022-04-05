#include <iostream>
using namespace std;

int main() {
    long A, B, count, big, small;
    
    cin >> A >> B;
    if (A == B) {
        count = 0;
    } else {
        if (A > B) {big = A; small = B;}
        else {big = B; small = A;}
        count = big - small - 1;
    }
    cout << count << endl;
    for (int i=1;i<=count;i++) {
        cout << small + i << " ";
    }
    cout << endl;
    return 0;
}