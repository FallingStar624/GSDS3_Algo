#include <iostream>

using namespace std;

int n,m;
int arr[10];
int val[10];
bool isused[10];

void func(int k, int s) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        if(val[i] >= s) {
            arr[k] = val[i];
            func(k+1, val[i]); 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if(val[j-1] > val[j]) {
                int tmp = val[j-1];
                val[j-1] = val[j];
                val[j] = tmp;
            } else {
                break;
            }
        }
    }

    func(0, 0);

    return 0;
}