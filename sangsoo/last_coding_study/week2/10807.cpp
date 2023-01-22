#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, num, v;
    cin>> n;
    int arr[201]; // -100<=v<=100
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        arr[num+100]++;
    }
    cin >> v;
    cout << arr[v+100];
}