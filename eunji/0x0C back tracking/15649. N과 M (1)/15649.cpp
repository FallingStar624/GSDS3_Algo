/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
(1 <= M <= N <= 8)
*/

#include <bits/stdc++.h>
using namespace std;

// Definition
int n,m;
int arr[10];
bool isused[10]; 
//if the specific number is used (true) or not (false)
// ex. n=4, m=3 : status with 3, 2 used
// arr[0] = 3, arr[1] = 2
// isused[1] = false, isused[2] = true, isused[3] = true, isused[4] = false
void func(int k);
// decide arr[k] in the status of k numbers dicided
// ex. when arr[0] is decided with func(0), then func(1) is called


int main(void){
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m;
  func(0);
}

void func(int k){
  // when all m numbers are decided, print out the answers
  if (k == m) {
    for (int i = 0; i<m; i++){
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  // we need to find what number is not used yet
  for (int i=1; i<=n; i++){
    if (!isused[i]){
      isused[i] = true;
      arr[k] = i;
      func(k+1);
      isused[i] = false;
    }
  }

}