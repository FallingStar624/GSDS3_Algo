#include <bits/stdc++.h>
using namespace std;
int cnt[10];
    
int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a;
    cin>>a;
    while (a>10 )
    {
        cnt[a%10]++;
        a/=10;
    }
    cnt[a%10]++;
    int max=0,max_idx=0;
    for (int idx=0;idx<10;idx++)
    {
        if (max<cnt[idx])
        {
            max = cnt[idx];
            max_idx=idx;
        }
    }
    if (max_idx==6 ||max_idx==9)
    {
        int mid=ceil((cnt[6]+cnt[9])/2.0);
        cnt[6]=mid;
        cnt[9]=mid;
    }
    max = 0;
    for (int i=0;i<10;i++){
        if (max<cnt[i])
        {
            max = cnt[i];
        }
    }
    cout<<max;
}