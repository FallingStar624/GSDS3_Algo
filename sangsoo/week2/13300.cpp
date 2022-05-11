#include <bits/stdc++.h>
using namespace std;
int male[7];
int female[7];
int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0; i <n ; i++){
        int gender;
        int grade;
        cin >> gender >> grade;
        if (gender ==0) female[grade]++;
        else male[grade]++;
    }

    int room = 0;
    for(int i=1; i <=6; i++){
        if(male[i]%k ==0) room += male[i]/k;
        else room += male[i]/k +1;
    }
    for(int i=1; i <=6; i++){
        if(female[i]%k ==0) room += female[i]/k;
        else room += female[i]/k +1;
    }
    cout << room << '\n';
}