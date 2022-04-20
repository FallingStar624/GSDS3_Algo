#include <iostream>
using namespace std;

int main() {
    int size = 9;
    int idx[size], num; 
    int max = 0;

    for (int i=0;i<size;i++){
        cin >> num;
        idx[i] = num;
        if (num > max) {
            max = num;
        }
    }
    cout << max << endl;
    for (int j=0;j<size;j++) {
        if (max == idx[j]) {
            cout << j+1 << endl;
            break;
        }
    }

    return 0;
}