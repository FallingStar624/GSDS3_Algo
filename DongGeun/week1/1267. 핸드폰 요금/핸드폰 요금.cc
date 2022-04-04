#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin>>n;
    int arr[n];
    int Y=0;
    int M=0;
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        Y+=(arr[i]/30)*10+10;
        M+=(arr[i]/60)*15+15;
    }
    if (Y<M)
    {
        cout<<"Y "<<Y;
    }
    else if (M<Y)
    {
        cout<<"M "<<M;
    }
    else
    {
        cout<<"Y M "<<M;
    }
}
    