#include <bits/stdc++.h>
using namespace std;

int n,m,k,elem,cnt;
vector <string> v;
string s;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    for (int i=0;i<s.size();i++)
    {
        v.push_back(s.substr(i, s.size()));
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++)
    {
        cout<<v[i]<<'\n';
    }
}