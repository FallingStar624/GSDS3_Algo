#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector <tuple<int,int,string>> v;
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
        cin>>s;
        int cnt=0;
        for(int i = 0; i < s.size(); i++){ 
            if(isdigit(s[i])) cnt += (s[i] - '0');
        }
        v.push_back(make_tuple(s.size(),cnt,s));
    }

    sort(v.begin(), v.end());
    for (int i=0;i<n;i++)
    {
        auto tup = v[i];
        cout<<get<2>(tup)<<'\n';
    }

}
