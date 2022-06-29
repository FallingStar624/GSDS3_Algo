#include <iostream>
using namespace std;


int solve(int y, int x, int n, int k){

    printf("(%d, %d)\n", y, x);
    if(k==0){
        if(n == 1){
            if     (y==0 && x == 0) return 2;
            else if(y==0 && x == 1) return 3;
            else if(y==1 && x == 0) return 1;
            else if(y==1 && x == 1) return 4; 
        }
    }
    else{
        if(n == 1){
            if     (y==0 && x == 0) return 4;
            else if(y==0 && x == 1) return 3;
            else if(y==1 && x == 0) return 1;
            else if(y==1 && x == 1) return 2; 
        }
    }

    int half = 1<<(n-1);
    // 1번 사각형
    if     (y < half && x <  half) return (half*half) + solve(n-1, y, x, k);
    // 2번 사각형
    else if(y < half && x >= half) return 2*(half*half) + solve(n-1, y, x-half, k);
    // 3번 사각형
    else if(y >= half && x < half) return solve(n-1, y-half, x, k);
    // 4번 사각형
    else                           return 3*(half*half) + solve(n-1, y-half, x-half, k);

}







int main(){
    int n,y,x; n=4;y=3;x=4;
    int k = n/2;
    int res = solve(y,x,n,k);
    printf("%d", res);
}