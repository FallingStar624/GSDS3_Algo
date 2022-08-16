// 1st row: # of cards N (1<=, =<100,000)
// 2nd row ~ : int (-2^62 ~ 2^62) -> long long
// most frequent int (same freq -> smaller)
// 2910 -> earlier input first

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n; 
long long num;
//map <int, int> freq; 

bool comp(pair<long long, int> &a, pair<long long, int> &b){
    if (a.second == b.second) // freq 동일하면
        return a<b; // 크기 순으로
    else
        return a.second > b.second; // freq 대로 정렬 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    map <long long, int> m; // input n 정보 -> in main
    
    for(int i = 0; i < n; i++) {
        cin >> num;
        //v.push_back(num);
        m[num]++; //+= 1;
    }

    vector<pair<long long, int>> v(m.begin(), m.end()); // copy map to vector
	sort(v.begin(), v.end(), comp);

	cout << v[0].first <<"\n";

    return 0;
}

// https://se-jung-h.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98C-%EB%B0%B1%EC%A4%80-11652-%EC%B9%B4%EB%93%9C