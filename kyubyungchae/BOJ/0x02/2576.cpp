#include <iostream>
using namespace std;



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input;
    int arr[7] = {0};
    int num_min = 100;
    for(int i = 0; i < 7; i++) {
        cin >> input;
        
        if (input % 2 != 0) {
            arr[i] = input;

            if (input < num_min) {
                num_min = input;
            }
        }
    }
    int sum = 0;
    for (int i=0; i < 7; i++) {
        sum += arr[i];
    }

    if (num_min == 100) {
        cout << -1;
    } else {
        cout << sum << '\n';
        cout << num_min;

    }

    return 0;
}