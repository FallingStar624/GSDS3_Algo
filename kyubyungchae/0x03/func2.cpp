#include <iostream>

using namespace std;

int func2(int arr[], int N) {

    int occur[101] = {};
    
    for(int i = 0; i < N; i++) {
        if(occur[100-arr[i]])
            return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}

int main() {
    int input[] = {1, 52, 48};
    int output = func2(input, 3);

    cout << output << '\n';
    // cout << func2({50, 42}, 2) << '\n';
    // cout << func2({4, 13, 63, 87}, 4) << '\n';

    return 0;
}