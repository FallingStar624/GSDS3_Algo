#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n;
  cin >> n;
  int arr[10] = {0};

  while(true){
      arr[n%10]++; // get unit
      if(n/10 ==0) break; // move forward
      n /= 10;
  }

  int num = 0;
  for(int i = 0 ; i < 10 ; i ++){
      if(i !=9 && i !=6) num = max(num, arr[i]); // found set by maximum number without 6,9
  }
  cout << max(num, (arr[6] + arr[9] +1) /2) ; // 6,9 are exchangable, "+1" is essential  
}