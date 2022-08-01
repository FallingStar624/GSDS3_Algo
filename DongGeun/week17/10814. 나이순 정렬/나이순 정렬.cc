#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <pair<int,string>> v;
string s;

bool compare(pair<int,string> a , pair<int,string> b)
{
    return a.first < b.first;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin>>m>>s;
        v.push_back(make_pair(m,s));
    }

    stable_sort(v.begin(), v.end(),compare);
    for (int i=0;i<n;i++)
    {
        auto pair = v[i];
        cout<<pair.first<<' '<<pair.second<<'\n';
    }

}
