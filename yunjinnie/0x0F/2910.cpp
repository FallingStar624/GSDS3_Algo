// # of seq: N(<=1000), all num <=C (1,000,000,000) -> 빈도순 정렬
// freq(X)>freq(Y) -> X first, if same freq -> earlier input first

#include <iostream>
#include <algorithm>
#include <vector> // for map
#include <map> // key 중복 허용 x
using namespace std;

//int arr[n];

int n, c;
int num;
map <int, int> freq;
map <int, int> idx;
//vector <pair<int, int>> v(freq.begin(), freq.end());

/*struct s{
    int n;
    int cnt;
    int ord;
};

int freq(int a[], int n){
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (a[i]==a[i+1])
            cnt++;
    return cnt;
    }
}

bool comp(s &a, s &b){
    //if (freq(a)==b.length())
    if (a.cnt>b.cnt) return true;
    if (a.cnt==b.cnt) return a.ord<b.ord;
    else return false;

} */

bool comp(pair<int, int> &a, pair<int, int> &b){
    if (a.second == b.second) // freq 동일하면
        return idx[a.first] < idx[b.first]; // index 순서대로
    else
        return a.second > b.second; // freq 대로 정렬 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    
    for(int i = 0; i < n; i++) {
        cin >> num;
        //v.push_back(num);
        freq[num]++; //+= 1;

        //??
        if (idx[num]==0) idx[num] = i+1;
    }

	// global로 선언하면 출력 안되는 이유 ... freq에 원소 담기 전에 선언해서?
	vector<pair<int, int>> v(freq.begin(), freq.end()); 
    //sort(v.begin(), v.end());
    sort(v.begin(), v.end(), comp);

    for (auto x : v){
        for (int i=0; i<x.second; i++){ // for (auto i: v)
            cout<< x.first <<' ';
        }
    }
    
    return 0;
}

// https://www.geeksforgeeks.org/find-frequency-number-array/
// https://velog.io/@al_potato/c-%EB%B0%B1%EC%A4%80-2910%EB%B2%88-%EB%B9%88%EB%8F%84-%EC%A0%95%EB%A0%AC