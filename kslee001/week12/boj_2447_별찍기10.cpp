#include <iostream>
using namespace std;

int pic[6561][6561];

void blank(int y, int x, int n){
    for(int i=y; i<y+n; ++i){
        for(int j=x; j<x+n; ++j){
            pic[y+i][x+j] = 0;
        }
    }
}

void star(int y, int x, int n){
    if(n==3){
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(i==1 && j==1){pic[y+i][x+j] = 0;}
                else            {pic[y+i][x+j] = 1;}
            }
        }
        return;
    }
    int step = n/3;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(i==1 && j==1){
                blank((y+i*step), (x+j*step), step);
            }
            else{
                star((y+i*step), (x+j*step), step);
            }
        }
    }
}

int main(){
    int n; cin>>n;
    star(0,0,n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(pic[i][j]==0) cout << ' ';
            else cout << "*";
        }
        if(i!=n-1) cout <<"\n";
    }
}