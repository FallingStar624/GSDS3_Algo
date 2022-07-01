#include<bits/stdc++.h>
using namespace std;
/*
15663 - 8

4 2
9 7 9 1

1 7
1 9
7 1
7 9
9 1
9 7
9 9
*/

void func(int k, int n, int m, int*arr, int* used, int* sorted){
    if(k == m){
        for(int i=0; i<m; ++i){
            printf("%d ", arr[i]);
            }
        printf("\n");
        return;
    }
    int t=0;
    for(int i=0; i<n; ++i){
        if(!used[i] && t!= sorted[i]){
            used[i] = 1;
            arr[k] = sorted[i];
            t = arr[k];
            func(k+1, n,m,arr,used,sorted);
            used[i] = 0;
        }
    }


}

int main(){
    int n,m;    scanf("%d%d", &n,&m);
    int arr[m]; memset(arr, 0, m*sizeof(int));
    
    int sorted[n];
    for(int i=0; i<n; ++i){ scanf("%d", &sorted[i]); }
    sort(sorted, sorted+n);
    
    int used[n];
    memset(used, 0, n*sizeof(int));
    
    func(0,n,m,arr,used,sorted);
}