// 1st row: # of guitar = N(<=50)
// 2nd row ~ : # of serial (<=50), A-Z or num, 중복 x
// sort: if A.len =/= B.len -> shorter first
// if same len -> 각 자리 수의 합, smaller first
// 둘 다 아니면 asc, num < A

#include <iostream>
#include <string>
//#include <vector>
#include <algorithm> // for sort
using namespace std;

int n;

// 각 자리 수의 합
int intSum(string a){
    int res = 0;
    int len = a.length();
    for (int i=0; i<len; i++){
        //only int
        if (a[i]-'0'>=0 && a[i]-'0'<=9) res+=a[i]-'0';
    }
    return res;

}

bool comp(string a, string b){
    if (a.length()==b.length()){
        if (intSum(a)==intSum(b)) return a<b; 
        // 없으면 4번 틀림 (input 순서) -> 사전 순 정렬
        return intSum(a)<intSum(b);
    }
    else return a.length()<b.length();

}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  string s[n]; //(n)
  
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s+n, comp); // s.begin()

  for (int i=0; i<n; i++){ // for (auto i: v)
    cout<<s[i]<<'\n';
    }
  return 0;
}

// https://saycoding.tistory.com/3