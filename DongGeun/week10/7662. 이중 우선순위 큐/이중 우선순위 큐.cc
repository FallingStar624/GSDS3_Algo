#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int K,N,M;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >>K;
    while (K--)
    {
        char ch;
        cin>>N;
        multiset<int> s;
        while (N--)
        {
            cin>>ch>>M;
            if (ch=='I')
            {
                s.insert(M);
            }
            else
            {
                if (s.empty()) continue;
                if (M==1) s.erase(prev(s.end()));
                else s.erase(s.begin());
            }
        }
        if (s.empty()) cout<<"EMPTY\n";
        else {
            cout << *prev(s.end())<< ' '<<*s.begin()<<'\n';
        }
    }

}