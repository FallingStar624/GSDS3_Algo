#include <bits/stdc++.h>
using namespace std;

int board[8][8];
int clone[8][8];

int n,m;
int mn = 0;


vector<pair<int,int>> cams;
vector<int> type;
int num=0;
void debug(int arr[][8]){printf("\n\n");for(int i=0; i<n; ++i){for(int j=0; j<m; ++j){printf("%d ", arr[i][j]);} printf("\n");}}
void mapping(){scanf("%d%d", &n,&m);for(int i=0; i<n; ++i){for(int j=0; j<m; ++j){int input; scanf("%d", &input); board[i][j] = input;}}}
void find_cameras(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(board[i][j]!=0 && board[i][j]!=6){
                cams.push_back({i,j});
                type.push_back(board[i][j]);
                num++;
            }
            if(board[i][j] == 0){
                mn ++;
            }
        }
    }
}
bool oob(int y, int x){return y<0 || y>=n || x<0 || x>=m;}
bool wall(int y, int x){return board[y][x] == 6;}
bool empty(int y, int x){return board[y][x] == 0;}

void upfill(int cur_y, int cur_x){int y=--cur_y; int x=cur_x; while(!oob(y,x) && !wall(y,x)){if(empty(y,x)) clone[y][x] = 9;y--;}}
void downfill(int cur_y, int cur_x){int y=++cur_y; int x=cur_x; while(!oob(y,x) && !wall(y,x)){if(empty(y,x)) clone[y][x] = 9; y++;}}
void rightfill(int cur_y, int cur_x){int y=cur_y; int x=++cur_x; while(!oob(y,x) && !wall(y,x)){if(empty(y,x)) clone[y][x] = 9; x++;}}
void leftfill(int cur_y, int cur_x){int y=cur_y; int x=--cur_x; while(!oob(y,x) && !wall(y,x)){if(empty(y,x)) clone[y][x] = 9; x--;}}

void randomfill(int y, int x, int dir){
    dir = dir%4;
    if(dir == 0){upfill(y,x);}
    if(dir == 1){rightfill(y,x);}
    if(dir == 2){downfill(y,x);}
    if(dir == 3){leftfill(y,x);}
}

int main(){
    mapping();
    find_cameras();

    for(int tmp = 0; tmp < (1<<(2*cams.size())); ++tmp){
        for(int i=0; i<n; ++i){
            // init
            for(int j=0; j<m; ++j){
                clone[i][j] = board[i][j];
            }
        }
        int brute = tmp;
        for(int i=0; i<cams.size(); ++i){
            int dir = brute %4;
            brute /=4;
            int y = cams[i].first;
            int x = cams[i].second;
            if(type[i] == 1){
                randomfill(y, x, dir);
            }
            else if(type[i] == 2){
                randomfill(y, x, dir);
                randomfill(y, x, dir+2);
            }
            else if(type[i] == 3){
                randomfill(y,x,dir);
                randomfill(y,x,dir+1);
            }
            else if(type[i] == 4){
                randomfill(y,x,dir);
                randomfill(y,x,dir+1);
                randomfill(y,x,dir+2);
            }
            else{
                randomfill(y,x,dir);
                randomfill(y,x,dir+1);
                randomfill(y,x,dir+2);
                randomfill(y,x,dir+3);
            }
        }
        int val = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                val += (clone[i][j]==0);
            }
        }
        mn = min(mn, val);
    }
    cout << mn;
}