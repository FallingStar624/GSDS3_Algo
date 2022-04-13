#include <bits/stdc++.h>
using namespace std;

int tmp[10000001];
int arr[1000001];

int main(){
    int n, x; 
    int count = 0;
    cin >> n;

    for(int i=0; i<n ; i++)  cin >> arr[i]; //insert n numbers
    cin >> x; // input x(sum)

    for(int i=0; i<n; i++){
        if (tmp[x - arr[i]] == 1)
            count++;
        else
            tmp[arr[i]] =1;
    }
    cout << count;
    return 0;
}