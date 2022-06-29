#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;



int map[128][128];
int cnt[2]; // 0->0 , 1->1

bool check(int y, int x, int n){
    for(int i=y; i<y+n; ++i){
        for(int j=x; j<x+n; ++j){
            if(map[i][j]!=map[y][x]){
                return false;
            }
        }
    }
    return true;
}

void solve(int y, int x, int z){
    if(check(y,x,z)){
        cnt[ map[y][x] ]++;
        return;
    }
    int n = z/2; // half down the sides

    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            solve( (y + i*n), (x + j*n), n);
        }
    }

}


int main(){
    int n; cin >>n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>map[i][j];
        }
    }    
    solve(0, 0, n);
    printf("%d\n%d", cnt[0], cnt[1]);

}