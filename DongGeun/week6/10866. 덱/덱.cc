#include <bits/stdc++.h>
using namespace std;
int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  deque<int> Q;
  while(N-->0)
  {
      string st;
      cin>>st;
      int K;
      if (st=="push_front")
      {
          cin>>K;
          Q.push_front(K);
      }
      else if (st=="push_back")
      {
          cin>>K;
          Q.push_back(K);
      }
      else if (st=="pop_front")
      {
          if (Q.empty()) cout<<"-1"<<'\n';
          else 
          {
              cout<<Q.front()<<'\n';
              Q.pop_front();
          }
      }
      else if (st=="pop_back")
      {
          if (Q.empty()) cout<<"-1"<<'\n';
          else 
          {
              cout<<Q.back()<<'\n';
              Q.pop_back();
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
      else if (st=="back")
      {
          if (Q.empty()) cout<<"-1"<<'\n';
          else cout<<Q.back()<<'\n';
      }
  }
}