#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int d = a*b*c;
  int arr[10] = {0}; // max d < 1,000,000,000
  
  while (d != 0){  // get units and move forward
      arr[d%10] +=1;
      d /= 10;
  }
  for(int i=0; i<10; i++){
      cout << arr[i] <<endl;
  }
}

/* failed code 
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int d = a*b*c;
  string d_chged = to_string(d);
  for(int i = 1; i < 10; i++){
    int cnt = 0;
    for(auto j: d_chged)
      if (j == d_chged) cnt ++;
    cout << cnt <<'\n';
  }
} */