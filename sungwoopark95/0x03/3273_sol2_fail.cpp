#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
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
    int diff;
    bool exists;
    for (int j=0;j<n;j++) {
        diff = condition - sequence[j];
        exists = find(&sequence[j+1], &sequence[n], diff) != &sequence[n];
        if (exists) {
            pairs += 1;
        }
    }

    cout << pairs << "\n";

    return 0;
}