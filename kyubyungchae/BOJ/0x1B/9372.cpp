#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <functional>    // greater, less

using namespace std;



int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;

    int a, b;
    while(m--) cin >> a >> b;
    cout << (n-1) << '\n';
  }
}