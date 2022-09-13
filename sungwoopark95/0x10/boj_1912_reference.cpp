#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int arr[100005], D[100005];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
        D[i] = arr[i];
    }
    
    int maximum = INT_MIN;
    for (int i=1;i<=N;i++) {
        D[i] = max(D[i], D[i-1]+arr[i]);
        if (maximum < D[i]) { maximum = D[i]; }
    }
    
    cout << maximum << "\n";
    
    return 0;
}