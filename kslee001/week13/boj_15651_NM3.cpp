#include <iostream>
using namespace std;

/*

input : 4 2
output : 
1 1
1 2
1 3
1 4
2 1
2 2
2 3
2 4
3 1
3 2
3 3
3 4
4 1
4 2
4 3
4 4
*/

int n,m;
int arr[10];
int used[10];

void func(int k){
    if(k == m){
        for(int i=0; i<m; ++i){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1; i<=n; ++i){
        if(1){
            arr[k] = i;
            used[i] = 1;
            func(k+1);
            used[i] = 0;
        }
    }
}



int main(){
    scanf("%d%d", &n,&m);
    func(0);
}