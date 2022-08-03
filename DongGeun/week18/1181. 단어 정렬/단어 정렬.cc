#include <bits/stdc++.h>
using namespace std;

int n;
vector <pair<int,string>> v;
string s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(make_pair(s.size(),s));
    }
    string tmp;
    sort(v.begin(), v.end());
    for (int i=0;i<n;i++)
    {
        auto second = v[i].second;
        if (second==tmp) continue;
        cout<<second<<'\n';
        tmp = second;
    }

}