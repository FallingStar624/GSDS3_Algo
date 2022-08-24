#include <iostream>
using namespace std;

int N;
int d[1005];
int idx[1005];
int sum[1005];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> d[i];
    }
    
    sum[0] = d[0];
    idx[0] = 0;
    for (int i=1;i<N;i++) {
        if (d[i] > d[i-1]) {
            sum[i] = sum[i-1] + d[i];
            idx[i] = i-1;
        } else {
            int k = idx[i-1];
            while (d[k] > d[i]) {
                k--;
            }
            sum[i] = sum[k] + d[i];
        }
    }
    
    int maximum = -1;
    for (int i=0;i<N;i++) {
        if (maximum < sum[i]) {
            maximum = sum[i];
        }
    }
    
    cout << maximum;
    
    return 0;
}