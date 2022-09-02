#include <iostream>
#define MAX 1010
using namespace std;

int N, max_elm;
int arr[MAX];
int d[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
        d[i] = 1;
    }
    
    for (int i=1;i<=N;i++) {
        for (int j=1;j<i;j++) {
            if (arr[j] < arr[i]) { d[i] = max(d[i], d[j]+1); }
        }
        if (max_elm < d[i]) { max_elm = d[i]; }
    }

    cout << max_elm << "\n";
    
    return 0;
}