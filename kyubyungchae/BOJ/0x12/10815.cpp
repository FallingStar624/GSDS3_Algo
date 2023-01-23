#include <iostream>
#include <algorithm>

using namespace std;

int arr_num[20000004];

int func_check_num(int num, int len, int start, int end) {

    int mid = (start + end) / 2;

    if(start > end) {
        return 0;
    }

    if(num == arr_num[mid]) {
        return 1;
    } else if(num < arr_num[mid]) {
        return func_check_num(num, len, start, mid-1);
    } else {
        return func_check_num(num, len, mid+1, end);
    }

    return 0;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    int i = 0;
    while(n--) {
        int num;
        cin >> num;
        arr_num[num]++;
    }

    sort(arr_num, arr_num + i);

    cin >> m;
    while(m--) {
        int check_num;
        cin >> check_num;
        cout << func_check_num(check_num, i, 0, i-1) << " ";
    }
    cout << '\n';


    return 0;
}