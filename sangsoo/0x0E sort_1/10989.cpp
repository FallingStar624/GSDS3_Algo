// solution
#include <bits/stdc++.h>
using namespace std;
int n, num;
int arr[10001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num; arr[num]++;
  }
  for(int i = 1; i <= 10000; i++){
    while(arr[i]){
      cout << i << '\n'; arr[i]--;
    }
  }
  return 0;
}