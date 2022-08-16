#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n;
long long num;
int res;
int maxf = 0;

int freq(vector<long long> v){ // arr[]= *arr, &
    int cnt = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i]==v[i+1]) { // 1 1 1 2 -> 
            cnt++;
            if (maxf < cnt) {
                maxf = cnt;
                res = v[i];
            }
        } else {
            cnt = 0;
        } 
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    vector <long long> v; // input n 정보 -> in main
    v.reserve(n);
    for(int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    v.resize(1);

    sort(v.begin(), v.end());
    res = freq(v);
    cout << res;

    return 0;
}
