#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[10];
int val[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    int succesor = 0;
    if(k > 0)
        succesor = arr[k-1];

    for(int i = 0; i < n; i++) {
        if(!isused[i] & (tmp != val[i]) & (val[i] >= succesor)) {
            arr[k] = val[i];
            isused[i] = 1;
            tmp = val[i];
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> val[i];

    sort(val, val + n);

    func(0);

    return 0;
}