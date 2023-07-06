// N과 M(3)
// N개 중에서 M 개뽑는데, 중복 허용(복원추출 개념)해서 뽑기
#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[8];
void func(int k){
    if(k == m){
        for(int i=0 ; i < m ; i++){
            cout << arr[i] << ' ';
        }
        cout <<'\n';
        return;
    }
    for (int i = 1; i <= n; i++){
        arr[k] = i;
        func(k+1);
    }
}

int main(){
    ios::sync_with_stdio(0);;
    cin.tie(0);
    cin >> n >> m;
    func(0);
}