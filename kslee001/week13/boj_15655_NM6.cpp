#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;


/*
4 2
9 8 7 1

*/


void input_sort(int* arr, int n){
    // store data
    for(int i=0; i<n; ++i){scanf("%d", &arr[i]);}
    int s; int left;
    // sort data(insertion sort)
    for(int i=1; i<n; ++i){
        s = arr[i];
        left = i-1;
        while(left>=0 && s < arr[left]){
            arr[left+1] = arr[left];
            left--;
        }
        arr[left+1] = s;
    }
}

void func(int k, int n, int m, int* arr, int* used, int* sorted, stack<int> &last){
    if(k==m){
        for(int i=0; i<m; ++i){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    int cur;
    for(int i=0; i<n; ++i){
        cur = sorted[i];
        if(last.empty()){
            last.push(-1);
        }
        if(!used[i] && sorted[i]>= last.top()){
            arr[k] = sorted[i];
            used[i]= 1;
            last.push(sorted[i]);
            func(k+1, n, m, arr, used, sorted, last);
            used[i] = 0;
        }
    }

    while(!last.empty()){
        last.pop();
    }

}



int main(){
    int n, m;      scanf("%d%d", &n,&m);
    int arr[n];    memset(arr, 0, n*sizeof(int)); 
    int used[n];   memset(used, 0, n*sizeof(int));
    int sorted[n]; input_sort(sorted, n);
    stack<int> last;

    func(0, n, m, arr, used, sorted, last);




    

}