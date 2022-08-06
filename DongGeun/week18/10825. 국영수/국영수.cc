#include <bits/stdc++.h>
using namespace std;

int n,m,k,elem,cnt;
vector <tuple<int,int,int,string>> v;
string s;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0;i<n;i++) {
        cin>>s>>m>>k>>elem;
        v.push_back(make_tuple(-m,k,-elem,s));
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++)
    {
        cout<<get<3>(v[i])<<'\n';
    }
}