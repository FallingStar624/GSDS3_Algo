#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

int main(){
    cin >> n >> m;
    for (int i = m; i < n; i++) // arr[n] = {0,0, .. 0, 1,1,..., 1} 0이 m개
        arr[i] = 1;

    do{
        for (int i = 0 ; i < n; i++)
            if (arr[i] == 0){
                cout << i+1 << ' ';
            }
        cout << '\n';
    } while (next_permutation(arr, arr+n));
}