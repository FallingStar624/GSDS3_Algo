#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];

// 10C3 = 9C2 + 9C3

int func(int num, int start, int end) {

    if(start > end)
        return 0;


}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int i = 0;
    while(n--) {
        cin >> arr[i++];
    }

    sort(arr, arr+i);

    int ans = 0;
    for(int j = 0; j < i; j++) {
        ans += func(arr[j], 0, i-1);
    }

    cout << ans << '\n';

    return 0;
}