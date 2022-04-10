#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // initialize the sequence    
    int n;
    cin >> n;
    int sequence[n];
    for (int i=0;i<n;i++) {
        cin >> sequence[i];
    }

    // find the pair summed as the input
    int condition;
    cin >> condition;

    int pairs = 0;
    for (int j=0;j<n-1;j++) {
        for (int k=j+1;k<n;k++) {
            if (sequence[j] + sequence[k] == condition) {
                pairs += 1;
                break;
            }
        }
    }
    
    cout << pairs << "\n";

    return 0;
}