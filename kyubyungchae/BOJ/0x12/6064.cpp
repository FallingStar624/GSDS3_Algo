#include <iostream>
#include <math.h>

using namespace std;

/*
if x < M, x' = x + 1
if y < N, y' = y + 1

Greatest Common Divisor : 최대 공약수
-> 유클리드 호제법
GCD(A, B) = GCD(B, r) -> O(log(max(a,b)))

Least Common Multiple : 최소 공배수
*/

int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int solve(int m, int n, int x, int y){
  if(x == m) x = 0;
  if(y == n) y = 0;
  int l = lcm(m, n);
  for(int i = x; i <= l; i += m){
    if(i == 0) continue;
    if(i % n == y)
      return i;
  }
  return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << solve(m, n, x, y) << '\n';

    }


    return 0;
}