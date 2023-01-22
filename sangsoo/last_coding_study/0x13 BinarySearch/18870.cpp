// solution
#include <bits/stdc++.h>
using namespace std;

int n;
int x[1000005];
vector<int> tmp, uni; // unique
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){ // 모든수를  tmp에 넣고
        cin >> x[i];
        tmp.push_back(x[i]);
    }
    sort(tmp.begin(), tmp.end()); // 정렬
    for(int i = 0; i < n; i++){ // 이전수와 다르면 uni에 넣기
        if(i == 0 || tmp[i-1] != tmp[i])
            uni.push_back(tmp[i]);
    }
    for(int i = 0; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
        // x[i]가 등장하는 인덱스
}