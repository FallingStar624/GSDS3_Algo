#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long a,b;
    cin >> a>>b;
    if (a > b) 
        swap(a,b);
    long long diff=b-a-1;
    if (diff==0||diff==-1)
    {
        cout<<0<<'\n';
    }    
    else 
    {
        cout<<diff<<'\n';
        for (long long i=a+1;i<b;i++)
        {
            cout<<i<<' ';
        }
    }
}
   



