#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[5] = {3, 4, 1, 2, 3};
    sort(arr, arr+5);
    reverse(arr, arr+5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}