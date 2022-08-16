// 1st: # of test case
// 2nd : # of A = N, # of B = M
// 3rd : elements of A
// 4th : elements of B
// iterate

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num;
int n, m;
int ni, mi;
//vector<int> a, b;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> num;

  while(num--){
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++) {
        cin >> ni;
        a.push_back(ni);
    }
    for(int i = 0; i < m; i++) {
        cin >> mi;
        b.push_back(mi);
    }

    //descending
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    
    int cnt =0;

    for (int i=0; i<n; i++){ // for (auto i: v)
        for (int j=0; j<m; j++){
            if(a[i]>b[j]){
                cnt++;
            }
            else break;
        }

    }
    cout<<cnt+1<<'\n';

  }

  return 0;
}

// 하나씩 비교하면 시간초과 -> 이분탐색 / 완전탐색
// B에서 A보다 작은 수들 중 제일 큰 수의 인덱스를 찾기
// https://2jinishappy.tistory.com/249