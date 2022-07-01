#include <iostream>
#include <memory.h>
using namespace std;


void sort(int* sorted, int n){
    for(int i=0; i<n; ++i){scanf("%d", &sorted[i]);}
    int s, left;
    for(int i=1; i<n; ++i){
        s = sorted[i];
        left = i-1;
        while(left>=0 && s < sorted[left]){
            sorted[left+1] = sorted[left];
            left--;
        }
        sorted[left+1] = s;
    }
}


void func(int k, int n, int m, int* arr, int* sorted){
    if(k == m){
        int idx;
        for(int i=0; i<m; ++i){
            idx = arr[i];
            printf("%d ", sorted[idx]);
        }
        printf("\n");
        return;
    }

    for(int i=0; i<n; ++i){
        arr[k] = i;
        func(k+1, n, m, arr, sorted);
    }

}


int main(){
    int n,m; scanf("%d%d", &n,&m);
    int arr[m];    memset(arr,  0, m*sizeof(int));
    int sorted[n]; sort(sorted, n);

    func(0, n, m, arr, sorted);




    

}