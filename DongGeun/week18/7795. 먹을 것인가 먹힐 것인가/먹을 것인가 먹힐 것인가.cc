#include <bits/stdc++.h>
using namespace std;

int n,m,k,elem,cnt;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    while(n--)
    {
        vector <int> v,v2;

        cin>>m>>k;
        for (int i=0;i<m;i++)
        {
            cin>>elem;
            v.push_back(elem);
        }
        for (int i=0;i<k;i++)
        {
            cin>>elem;
            v2.push_back(elem);
        }
        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<k;j++)
            {
                if(v[i]>v2[j]) cnt++;
                else break;
            }
        }
        cout<<cnt<<'\n';
        cnt=0;
    }

}