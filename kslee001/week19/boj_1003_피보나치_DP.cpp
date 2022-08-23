#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;


/*
0 -> (1, 0)

1 -> (0, 1)
2 -> (1, 1)
3 -> (1, 2)
4 -> (2, 3)
5 -> (3, 5)
6 -> (5, 8)
7 -> (8, 13)
*/


int cnt[2];
int func(int n){
    if(n==0){
        cnt[0]++;
        return 0;
    }
    else if(n==1){
        cnt[1] ++;
        return 1;
    }
    else{
        return func(n-1) + func(n-2);
    }
}

int main(){
    int n; scanf("%d", &n);
    int res1[41];
    int res2[41];
    res1[0] = 1; res2[0] = 0;
    res1[1] = 0; res2[1] = 1;

    for(int i=2; i<41; ++i){
        res1[i] = res2[i-1];
        res2[i] = res2[i-2] + res2[i-1];
    }

    int input;
    for(int i=0; i<n; ++i){
        scanf("%d", &input);
        printf("%d %d", res1[input], res2[input]);
        if(i!=n-1) printf("\n");
    }


}