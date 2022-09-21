// natural num N, int K -> 이항 계수 (N K)
// 1st row: 1<=N<=10, 0<=K<=N

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
//bool prime;
//int arr[1000002] = {0, };
int ans=1;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;

    int cnt=1;

    for (int i=n; i>0; i--){
        if (cnt>k) break;
    //while (cnt<=k){
        ans = ans*i;
        cnt++;
        //cout<<ans<< '\n';
    }

    for (int i=k; i>0; i--){
        ans = ans/i;
    }

    cout<<ans;
    return 0;

}