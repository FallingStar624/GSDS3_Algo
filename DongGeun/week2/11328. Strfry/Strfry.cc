#include <bits/stdc++.h>
using namespace std;
int n;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string fir,sec;
        cin>>fir>>sec;
        int fir_array[26]={};int sec_array[26]={};
        for (int a :fir)
        {
            fir_array[a-97]++;
        }
        for (int a :sec)
        {
            sec_array[a-97]++;
        }
        if(equal(fir_array, fir_array+26, sec_array))
            cout<<"Possible\n";
        else
            cout<<"Impossible\n";

    }
}