#include <bits/stdc++.h>
using namespace std;
int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  queue<int> Q;
  for (int i=0;i<N;i++)
  {
      Q.push(i+1);
  }
  while (Q.size()>1)
  {
      Q.pop();
      Q.push(Q.front());
      Q.pop();
  }
  cout<<Q.front();
}