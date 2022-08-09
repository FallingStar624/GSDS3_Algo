// suffix sort with 사전순 정렬 -> substr
// len(S)<=1000

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<string> v;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  
  for(int i = 0; i < s.length(); i++) {
    string sub = s.substr(i, s.length());
    v.push_back(sub); // i to l-1까지 쪼개서 vector에 넣음
  }

  sort(v.begin(), v.end()); // first element

  for (int i=0; i<v.size(); i++){
    cout<<v[i]<<'\n';
    }
  return 0;
}

// https://jaimemin.tistory.com/915