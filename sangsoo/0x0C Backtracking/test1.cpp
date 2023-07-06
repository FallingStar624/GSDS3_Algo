#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];
vector<int> v;
vector<vector<int>> vv;

void func(int k){
    if (k == m){
        vector<int> temp;
        for(int i =0 ; i < m; i++){
            temp.push_back(arr[i]);
        }
        vv.push_back(temp);
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

    for(auto &x : vv){
        for(int &y : x){
            cout << y << ' ';
        }
        cout << '\n';
    }
}
