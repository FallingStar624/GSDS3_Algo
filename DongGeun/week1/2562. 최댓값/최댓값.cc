#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a;
    int max=0;
    int idx=0;
    for (int i=0;i<9;i++)
    {
        cin >>a;
        if (a>max)
        {
            max =a;
            idx = i;
        }
        
    }
    cout<<max<<'\n'<<idx+1;
}