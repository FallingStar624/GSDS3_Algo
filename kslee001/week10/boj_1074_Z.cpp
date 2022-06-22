#include <iostream>
#include <cmath>
using namespace std;


int func(int n, int r, int c){
    if(n ==0) return 0;
    int half = 1<<(n-1);
    if(r < half && c < half) // 1번 사각형
        return func(n-1, r, c);
    if(r < half && c >= half) // 2번 사각형
        return half*half + func(n-1, r, c-half);
    if(r >= half && c < half) // 3번 사각형
        return 2*half*half + func(n-1, r-half, c);
    else                     // 4번 사각형
        return 3*half*half + func(n-1, r-half, c-half);
}


int main(){
    int n, r, c; scanf("%d%d%d",&n,&r, &c);
    int res = func(n,r,c);
    printf("%d", res);


}