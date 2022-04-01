#include <iostream>

using namespace std;

int main() {
    int total = 0;
    int minimum = 100;
    for (int i=0; i<7; i++) {
        int tmp;
        cin >> tmp;
        if (tmp%2) {
            total += tmp;
            if (tmp < minimum) minimum = tmp;
        }
    }
    if (total*minimum){
        cout << total << "\n";
        cout << minimum << "\n";
    } else cout << -1;
}

