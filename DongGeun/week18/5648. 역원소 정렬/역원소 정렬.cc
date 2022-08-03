#include <bits/stdc++.h>
using namespace std;

int n;
vector <long long> v;
string m;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin>>m;
        reverse(m.begin(), m.end());
        long long tmp = stol(m);
        if (tmp) v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    for (int i=0;i<v.size();i++)
    {
        cout<<v[i]<<'\n';
    }

}
