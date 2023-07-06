// N과 M(5)
// N과 M (1) 과 같은데(permutation)
// 다만 숫자가 1,2,3,.. 이 아니고 주어지는 숫자.
#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10]; bool isused[10001];
vector<int> v;
void func(int k){
    if(k==m){
        for(int i =0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(!isused[v[i]]){
            arr[k] = v[i];
            isused[v[i]] = 1;
            func(k+1);
            isused[v[i]] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    func(0);
}