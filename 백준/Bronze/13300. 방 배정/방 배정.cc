#include <bits/stdc++.h>
using namespace std;
int n,k,result;
float cnt[2][6];

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        int s,grade;
        cin>>s>>grade;
        cnt[s][grade-1]++;
    }
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<6;j++)
        {
            result+=ceil(cnt[i][j]/k);
        }
    }
    cout<<result;
}