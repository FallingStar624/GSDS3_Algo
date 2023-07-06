// N과 M(2) combination
// N개중에서 M개 뽑기 중복 미허용(조합 Combination)
#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int isused[10];
void func(int k){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 1; // 시작지점 k= 0이 일때 st = 1
    if(k != 0) st = arr[k-1]+1; // 이전에 쓰여진숫자보다 큰 수부터 적용
    for(int i = st; i <= n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);

}