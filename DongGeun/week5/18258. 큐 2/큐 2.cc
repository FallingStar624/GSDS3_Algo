#include <bits/stdc++.h>
using namespace std;
int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  queue<int> Q;
  while(N-->0)
  {
      string st;
      cin>>st;
      int K;
      if (st=="push")
      {
          cin>>K;
          Q.push(K);
      }
      else if (st=="pop")
      {
          if (Q.empty()) cout<<"-1"<<'\n';
          else 
          {
              cout<<Q.front()<<'\n';
              Q.pop();
          }
      }
      else if (st=="size")
      {
          cout<<Q.size()<<'\n';
      }
      else if (st=="empty")
      {
          if (Q.empty()) cout<<"1\n";
          else cout<<"0\n";
      }
      else if (st=="front")
      {
          if (Q.empty()) cout<<"-1"<<'\n';
          else cout<<Q.front()<<'\n';
      }
      else
      {
          if (Q.empty()) cout<<"-1"<<'\n';
          else cout<<Q.back()<<'\n';
      }
  }
}