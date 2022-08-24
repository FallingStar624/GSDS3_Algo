#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int d[1001];
/*
1. d[i] : i번째 수를 포함한 가장 큰 증가 부분 수열의 길이
2. 
if arr[i] > arr[j] : 증가 (j는 i보다 전)
    d[i] = max(d[i], d[j] + 1)
3. 초기값 d[i] = 1
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        d[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            if(arr[i] > arr[j]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    cout << *max_element(d + 1, d + n + 1);

    return 0;
}