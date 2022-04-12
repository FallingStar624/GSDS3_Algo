#include <bits/stdc++.h>
using namespace std;
#define MAX_DIFF 2000001

// 바킹독 예제 참고해서 풀었음
int cseq[MAX_DIFF];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // initialize the sequence    
    int n;
    cin >> n;
    int seq[n];
    for (int i=0;i<n;i++) {
        cin >> seq[i];
    }

    // find the pair summed as the input
    int condition;
    cin >> condition;
    int diff; int pairs = 0;
    for (int j=0;j<n;j++) {
        diff = condition - seq[j];
        if (diff < 0) continue;
        else {
            if (cseq[diff] == 0) {
                cseq[seq[j]] += 1;
            } else {
                pairs += 1;
            }
        }
    }
    cout << pairs << "\n";

    return 0;
}