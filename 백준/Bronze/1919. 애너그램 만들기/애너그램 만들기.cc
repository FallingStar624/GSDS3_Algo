#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string fir,sec;
    cin>>fir>>sec;
    int fir_array[26]={};
    int sec_array[26]={};
    int res=0;
    for (int a :fir)
    {
        fir_array[a-97]++;
    }
    for (int a :sec)
    {
        sec_array[a-97]--;
    }
    for (int i=0;i<26;i++)
    {
        int sum = fir_array[i]+sec_array[i];

        res+= sum>0? sum: sum*(-1);
    }
    cout<<res;

}