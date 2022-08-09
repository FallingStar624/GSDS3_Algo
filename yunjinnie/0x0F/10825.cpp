// 1st row: # of students: 1<=N<=100,000
// 2nd~ : name<=10 + 국 s1 + 영 s2 + 수 s3 (1<=score<=100)
// s1 desc, if s1 same -> s2 asc, if s1, s2 same -> s3 desc
// if all same -> name asc (A<a)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
    string name;
    int s1, s2, s3;
};

int n;
//vector<info> v;

bool comp(info &a, info &b){ // a? &a?
    // default: a<b -> asc
    if (a.s1==b.s1 && a.s2==b.s2 && a.s3==b.s3) return a.name < b.name;
    else if (a.s1==b.s1 && a.s2 == b.s2) return a.s3 > b.s3;
    else if (a.s1==b.s1) return a.s2 < b.s2;
    else return a.s1 > b.s1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  vector<info> v(n); // n 정보 들어온 다음이므로 main에서 선언
  // if no n-> seg fault

  for (int i=0; i<n; i++){
    cin >> v[i].name >> v[i].s1 >> v[i].s2 >> v[i].s3;
  }
  
  sort(v.begin(), v.end(), comp);

  for (int i=0; i<n; i++){
    cout<<v[i].name<<'\n';
    }
  return 0;
}

// https://code-kh-studio.tistory.com/63