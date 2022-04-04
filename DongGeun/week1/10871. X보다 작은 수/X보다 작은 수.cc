#include <iostream>
using namespace std;

int n, x, a[10000];
int main(void) {
  cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++)
      if(a[i] < x) 
      {
          cout << a[i] << ' ';
      }
}