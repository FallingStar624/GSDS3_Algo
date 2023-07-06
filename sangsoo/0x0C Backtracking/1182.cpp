// combination not permutation
#include <bits/stdc++.h>
using namespace std;

int n, s, sum, cnt;
int arr[22]; 

void func(int k){
    if(sum == s && k > 0){
        cnt++;
    }
    for(int i = k; i < n; i++){ // 시작지점이 k부터.. 
        sum += arr[i];
        func(i + 1);
        sum -= arr[i];
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
