#include <bits/stdc++.h>
using namespace std;
int N,cnt;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    cin>>N;
    while(N-->0)
    {
        stack<char> s;
        string str;
        cin>>str;
        for (auto ch:str)
        {
            if(s.empty())s.push(ch);
            else
            {
                if(ch=='A')
                {
                    if (s.top()=='A')
                    {
                        s.pop();
                    }
                    else s.push(ch);
                }
                else
                {
                    if (s.top()=='B')
                    {
                        s.pop();
                    }
                    else s.push(ch);
                }
            }
        }
        if(s.empty())cnt++;
    }
    cout<<cnt;
}