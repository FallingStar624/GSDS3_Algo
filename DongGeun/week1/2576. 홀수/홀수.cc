#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b;
    int sum=0;
    int min=100;
    for (int i=0;i<7;i++)
    {
        cin>>a;
        if (a%2==1)
        {
            sum+=a;
            min=  (min < a) ? min : a;
        }
    }
    if (sum==0)
    {
        cout<<-1<<'\n';
    }
    else
    {
        cout<<sum<<'\n';
        cout<<min<<'\n';
    }

}