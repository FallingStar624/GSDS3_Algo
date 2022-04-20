#include <bits/stdc++.h>

// #include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int row = 1 ; row <= n; row++){
        for(int i = 0; i < n-row; i++){
            cout << " ";
        }
        for(int i = 0; i < 2*row-1; i++){
            cout << "*";
        }
        // for(int i = 0; i < n-row; i++){
        //     cout << " ";
        // }
        cout << "\n";
    }
}