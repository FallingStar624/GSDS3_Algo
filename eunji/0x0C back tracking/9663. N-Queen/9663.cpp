/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
퀸은 상하좌우, 대각선으로 공격할 수 있음.
입력 : 첫째 줄에 N이 주어진다. (1 ≤ N < 15)
*/

#include <bits/stdc++.h>
using namespace std;

int n;
bool isused1[50];
// for column y, check if (x,y) is used
bool isused2[50];
// for diagonal x+y, check if (x,y) is used
bool isused3[50];
// for dianogal x-y+n-1, check if (x,y) is used
int cnt = 0; 

void func(int cur){
  if (cur == n){
    cnt++;
    return;
  }
  
  for (int i=0; i<n; i++){
    if ( (!isused1[i]) && (!isused2[i+cur]) && (!isused3[i-cur+n-1])){
      isused1[i] = true;
      isused2[i+cur] = true;
      isused3[i-cur+n-1] = true;
      func(cur+1);
      isused1[i] = false;
      isused2[i+cur] = false;
      isused3[i-cur+n-1] = false;      
    }
  //   if ( (isused1[i]) || (isused2[i+cur]) || (isused3[cur-i+n-1])) continue;
  //   isused1[i] = true;
  //   // cout << cnt;
  //   isused2[i+cur] = true;
  //   isused3[cur-i+n-1] = true;
  //   func(cur+1);
  //   isused1[i] = false;
  //   isused2[i+cur] = false;
  //   isused3[cur-i+n-1] = false;      
  // }
}
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
  return 0;  
}