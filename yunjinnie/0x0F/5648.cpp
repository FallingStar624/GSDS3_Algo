// positive n(<=1,000,000). input # line 제한 없음 (한 줄에 꼭 하나 아니어도 됨)
// element reverse : string -> sort ascending order : int

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
vector<long long> v;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  
  for(int i = 0; i < n; i++) {
    cin >> s;
    reverse(s.begin(), s.end());
    v.push_back(stoll(s));
  }

  sort(v.begin(), v.end());

  for (int i=0; i<n; i++){ // for (auto i: v)
        cout<<v[i]<<'\n';
    }
  return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    int n;
    //int seq[1000000];
    vector<string> v(n);
    vector<long long> ans; // out of main / int: segmentation fault
    // ans(n) -> all 0

    cin>>n;

    for (int i=0; i<n; i++){
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());
        ans.push_back(stoll(v[i]));
    }

    sort(ans.begin(), ans.end());

    for (int i=0; i<n; i++){ // for (auto i: v)
        cout<<ans[i]<<'\n';
    }

    return 0;

}*/

// https://hashcode.co.kr/questions/403/segmentation-fault%EB%8A%94-%EB%AD%94%EA%B0%80%EC%9A%94
// https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0F/solutions/5648.cpp