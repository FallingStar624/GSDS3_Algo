// N과 M (9)
// N과 M (1) 과 같은데(permutation)
// 다만 숫자가 1,2,3,.. 이 아니고 주어지는 숫자. + 중복

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];
vector<int> v;
vector<vector<int>> vv;

void func(int k){
    if (k==m){
        vector<int> tmp;
        for(int i=0; i < m; i++) 
            tmp.push_back(arr[i]);
        vv.push_back(tmp);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!isused[i]){
            isused[i] = 1;
            arr[k] = v[i];
            func(k+1);
            isused[i] = 0;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp;
    cin >> n >> m;
    for(int i = 0; i < n; i++){    
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    func(0);
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());
    for(auto &x: vv){
        for(int &y: x){
            cout << y << ' ';
        }
        cout << '\n';
    }
}