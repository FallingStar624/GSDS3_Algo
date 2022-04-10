#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, v;
    cin >> N;
    int arr[N];
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    cin >> v;

    // count
    int count = 0;
    for (int j=0;j<N;j++) {
        if (arr[j] == v) {
            count += 1;
        }
    }

    cout << count << "\n";
    return 0;
}