#include <bits/stdc++.h>
using namespace std;
int arr[16];
char res[16];
int n,m;
bool isused[16];

void func(int k,int cnt,int cnt2)
{
    if (k==n)
    {
        for (int i=0;i<n;i++)
        {
            if (res[arr[i]]=='a'||res[arr[i]]=='e'||res[arr[i]]=='i'||res[arr[i]]=='o'||res[arr[i]]=='u')cnt++;
            else cnt2++;
        }
        if (cnt>=1&&cnt2>=2)
        {
            //cout<<cnt<<" cnt\n";
            for (int i=0;i<n;i++)
            {
                cout<<res[arr[i]];
            }
            cout<<'\n';
        }
        return;
    }

    int st = 0;
    if(k != 0) st = arr[k-1];
    for(int i = st; i < m; i++){
        if(!isused[i])
        {
            arr[k] = i;
            isused[i]=1;
            func(k+1,cnt,cnt2);
            isused[i]=0;
        }
        cnt=0;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
         cin>>res[i];
    }
    sort(res,res+m);
    func(0,0,0);
}
