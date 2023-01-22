//solution
/*
binary search는 항상 정렬을 해야한다.
two[m] + a[k] = a[l]을 만족하는 a[l]중에 최댓값 (two[m]  = a[l] - a[k])
vector<int> two 두수의 합을 넣어놓고
그 두수의 합이 a[l]-a[k]인 것을 찾는다.

*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
vector<int> two;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++)
            two.push_back(a[i] + a[j]);
    }
    sort(two.begin(), two.end());
    for(int i = n-1; i > 0 ; i--){
        for(int j = 0; j < i; j++){
            if(binary_search(two.begin(), two.end(), a[i]-a[j])){
                cout << a[i]; // sort가 되어 있어서 뒤에서부터 확인해서 따로 max 구현 안해된다.
                return 0;
            }
        }
    }    
}