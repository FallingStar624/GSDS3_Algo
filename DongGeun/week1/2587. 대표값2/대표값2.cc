#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int arr[5],sum;
    for(int i = 0; i < 5; i++) 
        cin >> arr[i];
   
    for(int i = 0; i < 5; i++) 
        sum += arr[i];
    cout << sum / 5 << "\n";
    sort(arr, arr + 5);
    cout << arr[2];
}