// fail. permuation으로 접근..
#include <bits/stdc++.h>
using namespace std;

int n, s, sum, cnt;
int arr[22]; 
bool isused[22];
void func(int k){
    if (k>0 && sum == s){
        cnt++;
    }
    if (k == n){
        return;
    }
    for(int i = 0; i < n; i++){
        if(!isused[i]){
            isused[i] = 1;
            sum += arr[i];
            func(k+1);
            isused[i] = 0;
            sum -= arr[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    func(0);
    cout << cnt;
}