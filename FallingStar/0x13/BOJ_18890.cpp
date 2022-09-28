#include <iostream>
#include <algorithm>
using namespace std;
int N;
int a[1000000];
vector<int> v;

int find_idx(int target) {
    int st = 0;
    int en = v.size();
    while (st<en) {
        int mid = (st+en)/2;
        if (v[mid]>=target) {
            en = mid;
        } else {
            st = mid+1;
        }
    }
    return st;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0; i<N; i++) {
        cout << find_idx(a[i]) << " ";
    }
    return 0;
}
