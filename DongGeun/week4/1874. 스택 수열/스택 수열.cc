#include <bits/stdc++.h>
using namespace std;

int N,K;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    stack<int> S;
    S.push(0);
    vector <char> pm;
    bool flag=false;
    int check=1;
    while(N-->0)
    {
        cin>>K;
        while(S.top()<K)
        {
            if (K<check)
            {
                cout<<"NO";
                return 0;
            }
            S.push(check++);
            pm.push_back('+');
            //cout<<S.top()<<"is top\n";
        }
        S.pop();
        pm.push_back('-');
    }
    for (auto c: pm)cout<<c<<'\n';


}