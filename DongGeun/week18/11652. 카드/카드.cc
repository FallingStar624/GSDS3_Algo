#include <bits/stdc++.h>
using namespace std;

int n,cnt,mx;
long long m;
vector <long long> v;

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
    long long card = v[0];
    for (int i = 1; i < n; i++){
        if (v[i] == v[i - 1]) cnt++;
        else cnt = 0;
        if (cnt > mx){
            mx = cnt;
            card = v[i];
        }
    }
    cout << card;

}
