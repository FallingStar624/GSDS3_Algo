#include <bits/stdc++.h>
using namespace std;
int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  stack<int> S;
  while(N-->0)
  {
      string st;
      cin>>st;
      int K;
      if (st=="push")
      {
          cin>>K;
          S.push(K);
      }
      else if (st=="pop")
      {
          if (S.empty()) cout<<"-1"<<'\n';
          else 
          {
              cout<<S.top()<<'\n';
              S.pop();
          }
      }
      else if (st=="size")
      {
          cout<<S.size()<<'\n';
      }
      else if (st=="empty")
      {
          if (S.empty()) cout<<"1\n";
          else cout<<"0\n";
      }
      else
      {
          if (S.empty()) cout<<"-1"<<'\n';
          else cout<<S.top()<<'\n';
      }
  }
}