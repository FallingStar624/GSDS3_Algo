#include <iostream>
using namespace std;

int youngsik(int *arr, int size);
int minsik(int *arr, int size);

int main() {
    int ys, ms, numcalls;
    cin >> numcalls;
    int calls[numcalls];
    
    for (int i=0;i<numcalls;i++) {
        cin >> calls[i];
    }

    ys = youngsik(calls, numcalls);
    ms = minsik(calls, numcalls);

    if (ys > ms) {
        cout << "M " << ms << endl;
    } else if (ys < ms) {
        cout << "Y " << ys << endl;
    } else {
        cout << "Y M " << ys << endl;
    }

    return 0;
}

int youngsik(int *arr, int size) {
    int unit_fee = 10;
    int unit_len = 30;
    int sum = 0; int fee;
    for (int i=0;i<size;i++) {
        fee = unit_fee * ((arr[i] / unit_len) + 1);
        sum += fee;
    }
    return sum;
}

int minsik(int *arr, int size) {
    int unit_fee = 15;
    int unit_len = 60;
    int sum = 0; int fee;
    for (int i=0;i<size;i++) {
        fee = unit_fee * ((arr[i] / unit_len) + 1);
        sum += fee;
    }
    return sum;
}