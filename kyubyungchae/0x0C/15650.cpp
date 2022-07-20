#include <string>
#include <iostream>

using namespace std;

int n,m;
int arr[10];
bool isused[10];


void func(int k, int s) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isused[i] & (i > s)) {
            arr[k] = i;
            isused[i] = 1;
            func(k+1, i);
            isused[i] = 0;
        }
    }
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0, 0);

    return 0;
}