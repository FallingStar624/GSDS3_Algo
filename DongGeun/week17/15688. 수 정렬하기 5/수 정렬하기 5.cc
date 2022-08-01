#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin>>m;
        v.push_back(m);
    }

    sort(v.begin(), v.end());
    for (int i=0;i<n;i++)
    {
        cin>>m;
        cout<<v[i]<<'\n';
    }

}
