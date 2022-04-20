#include <iostream>
using namespace std;

int main() {
    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int temp, mid, mid2, a, b;
    for (int j=0;j<10;j++) {
        cin >> a >> b;
        a -= 1; b -= 1;
        if ((b-a) % 2 == 0) {
            mid = ((b+a)/2);
            int interval = b - mid; // 2
            for (int i=interval;i>0;i--) {
                temp = arr[mid-i];
                arr[mid-i] = arr[mid+i];
                arr[mid+i] = temp;
            }        
        } else {
            mid2 = (b-a) / 2;
            for (int i=0;i<(b-a-mid2);i++) {
                temp = arr[i+a];
                arr[i+a] = arr[b-i];
                arr[b-i] = temp;
            }
        }
    }

    for (int i=0;i<20;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
