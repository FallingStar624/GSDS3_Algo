#include <iostream>
using namespace std;

int sum(int arr[], int size);

int main() {
    int y1, y2, y3, y4;
    int ones;
    
    for (int round=0;round<3;round++) {
        cin >> y1 >> y2 >> y3 >> y4; 
        int arr[4] = {y1, y2, y3, y4};
        ones = sum(arr, 4); // 뒤집어진 윷가락 개수

        if (ones == 0) { // 뒤집어진 게 하나도 없으면 - 윷
            cout << "D" << endl;
        } else if (ones == 1) {
            cout << "C" << endl;
        } else if (ones == 2) {
            cout << "B" << endl;
        } else if (ones == 3) {
            cout << "A" << endl;
        } else {
            cout << "E" << endl;
        }
    }
}

int sum(int arr[], int size) {
    int total = 0;
    for (int i=0;i<size;i++) {
        total += arr[i];
    }
    return total;
}