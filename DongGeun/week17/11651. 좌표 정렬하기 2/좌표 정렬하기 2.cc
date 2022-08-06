#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector <pair<int,int>> v;

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
        cin>>m>>k;
        v.push_back(make_pair(k,m));
    }

    sort(v.begin(), v.end());
    for (int i=0;i<n;i++)
    {
        auto pair = v[i];
        cout<<pair.second<<' '<<pair.first<<'\n';
    }

}
