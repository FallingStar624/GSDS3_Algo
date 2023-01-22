//solution
#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;

int binarysearch(int target){
    int st = 0;
    int en = n-1;
    while(st <= en){
        int mid = (st+en)/2;
        if(a[mid] < target)
            st = mid + 1;
        else if(a[mid] > target)
            en = mid -1;
        else // a[mid] == target
            return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i =0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int m;
    cin >> m;
    while(m--){
        int t;
        cin >> t;
        cout << binarysearch(t) << '\n';
    }
}