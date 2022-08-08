#include <iostream>
#include <limits.h>
#include <map>
using namespace std;

int N;
map<long, int> cnt;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        long temp;
        cin >> temp;
        cnt[temp]++;
    }
    
    int max = INT_MIN;
    for (auto itr=cnt.begin();itr!=cnt.end();itr++) {
        if (max < itr->second) { max = itr->second; }
    }
    
    for (auto itr=cnt.begin();itr!=cnt.end();itr++) {
        if (max == itr->second) {
            cout << itr->first << "\n";
            return 0;
        }
    }
    return 0;
}