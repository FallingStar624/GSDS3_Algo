// N (<=20000) words, sort with length (short -> long), if same len: dictionary order
// 그 아래 단어들 차례로 주어짐
// + 중복 없어야 함

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
vector<string> v;

bool comp(string a, string b){
    if (a.length()==b.length()) // 길이 같을 경우 사전순 정렬
        return a<b;
    else // 길이 다를 경우 길이순 정렬
        return a.length()<b.length();

}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  
  for(int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end(), comp);

  for (int i=0; i<n; i++){ // for (auto i: v)
    if(v[i]==v[i+1]){ // 중복 시 건너뜀
        continue;
    }
    cout<<v[i]<<'\n';
    }
  return 0;
}

// https://beginnerdeveloper-lit.tistory.com/94