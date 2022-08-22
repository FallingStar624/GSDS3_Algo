#include <iostream>
using namespace std;
int n;
long long arr1[1001]; // 세로 하나
long long arr2[1001]; // 가로 하나
long long arr3[1001]; // 정사각형

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    arr1[1]=1;
    arr1[2]=1, arr2[2]=1, arr3[2]=1;
    for (int i=3; i<=n; i++) {
        arr1[i] = (arr1[i-1]+arr2[i-1]+arr3[i-1])%10007 ;
        arr2[i] = arr1[i-1];
        arr3[i] = arr1[i-1];
    }
    cout << (arr1[n]+arr2[n]+arr3[n])%10007;
    return 0;
}
