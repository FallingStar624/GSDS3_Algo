#include <bits/stdc++.h>
using namespace std;

vector <pair <int, string>> v;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first > b.first;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int m;
  string str;
  for(int i=0; i<n; i++){
    cin >> m >> str;
    v.push_back(pair<int, string>(m, str));
  }
  sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

}