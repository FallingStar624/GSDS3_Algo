#include <iostream>
#include <algorithm>
using namespace std;
int N;
int a[1000];
vector<int> v;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> a[i];
    }
    sort(a, a+N);
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            v.push_back(a[i]+a[j]);
        }
    }
    sort(v.begin(), v.end());
    for (int i=N-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (binary_search(v.begin(), v.end(), a[i]-a[j])) {
                cout << a[i];
                return 0;
            }
        }
    }
    return 0;
}
