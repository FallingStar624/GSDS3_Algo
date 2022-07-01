#include <bits/stdc++.h>
using namespace std;

void func(int k, int n, int m, int* arr, int* used, int* sorted, stack<int> &last){
    if(k == m){
        for(int i=0; i<m; ++i){printf("%d ", arr[i]);}
        printf("\n");
    }
    int t=0;
    for(int i=0; i<n; ++i){
        if(last.empty()) last.push(-1);
        if(t!=sorted[i] && last.top() <= sorted[i]){
            arr [k] = sorted[i];
            used[i] = 1;
            t = arr[k];
            last.push(sorted[i]);
            func(k+1, n,m,arr,used,sorted, last);
            used[i] = 0;
        }
    }
    while(!last.empty()) last.pop();
}


int main(){
    int n,m; scanf("%d%d", &n,&m);
    int arr[m]; int used[n]; int sorted[n];
    memset(arr, 0, m*sizeof(int));
    memset(used, 0, n*sizeof(int));
    for(int i=0; i<n; ++i){ scanf("%d", &sorted[i]);}
    sort(sorted, sorted+n);
    stack<int> last;
    func(0,n,m,arr,used,sorted, last);






}