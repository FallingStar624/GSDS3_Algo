#include <iostream>

using namespace std;

int main(void) {
    unsigned int arr[3];
    for (int i = 0; i < 3; i++) cin >> arr[i];
    unsigned int minimum = 1000001;
    for (int i=0; i<3; i++)
        for (int j =i+1; j<3; j++)
            if (arr[j] < arr[i]) {
                int small = arr[j];
                arr[j] = arr[i];
                arr[i] = small;
            }
    cout << arr[0] << " " << arr[1] << " " << arr[2];
}
