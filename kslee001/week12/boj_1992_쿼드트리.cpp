#include <iostream>
#include <memory.h>
#include <cmath>
#include <limits.h>
using namespace std;

int pic[64][64];

bool check(int y, int x, int n){
    for(int i=y; i<y+n; ++i){
        for(int j=x; j<x+n; ++j){
            if(pic[i][j] != pic[y][x]){
                return false;
            }
        }
    }
    printf("%d",pic[y][x]);
    return true;
}


void solve(int y, int x, int z){
    if(check(y,x,z)){
        return;
    }
    printf("(");
    int n = z/2;
    for(int i=0; i<2; ++i){
        for(int j=0; j<2;++j){
            solve ( y+(i*n), x+(j*n), n);
        }
    }
    printf(")");

    return;
}


int main(){    
    // generate picture matrix
    int n; scanf("%d", &n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%1d", &pic[i][j]);
        } 
    }
    solve(0,0,n);

    
}