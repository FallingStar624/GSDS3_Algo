#include <iostream>
using namespace std;

int smallest(int arr[], int start, int length);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int dwarf = 9;
    int sum = 0; int left = 0; int right = 0;
    int height[dwarf];
    int num, diff, duo;

    for (int k=0;k<dwarf;k++) {
        cin >> num;
        sum += num;
        height[k] = num;
    }

    // selection sort
    int small_idx;
    int arr_temp;
    for (int m=0;m<dwarf;m++) {
        small_idx = smallest(height, m, dwarf);
        if (height[m] > height[small_idx]) {
            arr_temp = height[m];
            height[m] = height[small_idx];
            height[small_idx] = arr_temp;
        }
    }

    diff = sum - 100;
    for (int i=0;i<dwarf;i++) {
        for (int j=0;j<dwarf;j++) {
            if (i != j) {
                duo = height[i] + height[j];
                if (duo == diff) {
                    left = i; right = j;
                }
            }
        }
    }

    for (int l=0;l<dwarf;l++) {
        if ((l != left) & (l != right)) {
            cout << height[l] << "\n";
        }
    }

    return 0;
}

int smallest(int arr[], int start, int length) {
    int temp = start;
    for (int i=start;i<length;i++) {
        if (arr[temp] > arr[i]) {
            temp = i;
        }
    }
    return temp;
}