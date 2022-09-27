#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int K, N;
long long maxlen = LLONG_MIN;
long long lans[10004];
vector<long long> v;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> K >> N;
    for (int i=0;i<K;i++) {
        cin >> lans[i];
        if (maxlen < lans[i]) { maxlen = lans[i]; }
    }

    long long start = 1;
    long long end = maxlen;
    while (start <= end) {
        long long mid = start + ((end-start)/2);
        
        int cnt = 0;
        for (int i=0;i<K;i++) { 
            cnt += (lans[i] / mid); 
        }
        
        if (cnt >= N) {
            v.push_back(mid);
            start = mid + 1;
        } else { // 자른 단위 길이가 길어서 원하는 가닥보다 적게 나왔다는 의미
            end = mid - 1;
        }
    }
    
    cout << *max_element(v.begin(), v.end()) << "\n";
    
    return 0;
}