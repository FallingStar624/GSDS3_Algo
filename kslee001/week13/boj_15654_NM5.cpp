#include <iostream>
#include <memory.h>
using namespace std;





void func(int k, int n, int m, int* arr, int* sorted, int* used){
    if( k== m){
        for(int i=0;i<m; ++i){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0; i<n; ++i){
        if(!used[i]){
            arr[k] = sorted[i];
            used[i] = 1;
            func(k+1, n, m, arr, sorted, used);
            used[i] = 0;
        }
    }
}


int main(){
    int n,m;
    scanf("%d%d", &n,&m);
    int arr [n]; memset(arr, 0, n*sizeof(int));   // for printing
    int used[n]; memset(used, 0, n*sizeof(int)); 

    int sorted[n]; // for sorting & storing
    for(int i=0; i<n; ++i){
        scanf("%d", &sorted[i]);
    }

    // insertion sort
    int smallest;
    int left;
    for(int i=1; i<n; ++i){     // for right partition
        smallest = sorted[i];
        left = i-1;
        while(left >= 0 && smallest < sorted[left] ){
            sorted[left+1] = sorted[left];
            left--;
        }
        sorted[left+1] = smallest;        
    }


    // function 
    func(0, n, m, arr, sorted, used);




}