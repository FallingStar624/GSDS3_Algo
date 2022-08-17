#include <iostream>
using namespace std;
int arr[305];
int d[305][3];
int main(){
    int n; cin>>n;
    for(int i=1; i<=n; ++i) cin >>arr[i];

    if(n==1){
        cout << arr[1];
        return 0;
    }

    d[1][1] = arr[1];
    d[1][2] = 0;
    d[2][1] = arr[2];
    d[2][2] = arr[1] + arr[2];
    for(int i=3; i<=n; ++i){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + arr[i];
        d[i][2] = d[i-1][1] + arr[i];
    }
    cout << max(d[n][1], d[n][2]);
}