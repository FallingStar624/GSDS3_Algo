#include <bits/stdc++.h>
using namespace std;
int cnt[10];
    
int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    //string num_str1(std::to_string(a*b*c));
    int mul = a*b*c;
    while (mul>10 )
    {
        cnt[mul%10]++;
        mul/=10;
    }
    cnt[mul%10]++;
    for (int i=0;i<10;i++){
        cout<<cnt[i]<<'\n';
    }
}