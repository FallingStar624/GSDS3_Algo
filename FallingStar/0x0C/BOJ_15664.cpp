#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[10];
int num[10];
bool isUsed[10];

void back_track(int cnt) {
    if (cnt == m) {
        for (int i=0; i<m; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int check = 0;
    for (int i=0; i<n; ++i) {
        if (!isUsed[i] && check != num[i] && num[i]>=arr[cnt-1]) {
            isUsed[i]=true;
            arr[cnt] = num[i];
            check = arr[cnt];
            back_track(cnt+1);
            isUsed[i]=false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        cin >> num[i];
    }
    sort(num, num+n);
    back_track(0);
    return 0;
}
