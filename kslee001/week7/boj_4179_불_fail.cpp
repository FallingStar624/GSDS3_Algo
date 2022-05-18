#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

int cur_i;
int cur_j;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int new_i;
int new_j;

int room[1000][1000];
int arv [1000][1000];
int f_arv[1000][1000];
int escape_time[1000][1000];
int fire_time  [1000][1000];

int main(){
    int n, m; cin >>n>>m;

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            arv[i][j] = 0;
            f_arv[i][j] = 0;
            escape_time[i][j] = -2;
            fire_time[i][j] = -1;
        }
    }

    int num_exit = 0;

    queue<pair<int,int>> que;
    int que_size;
    char input;
    // 1. generate room
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> input;
            if(input == '#'){
                room[i][j] = 1;
            }
            else if (input == 'J'){
                room[i][j] = 7;                
            }
            else if (input == 'F'){
                room[i][j] = 3;
            }
            else{
                room[i][j] = 0;
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    num_exit ++;
                }
            }
        }
    }

    // 2-1 set initial safe area
    for(int i=0; i<n; ++i){
        for(int j= 0; j<m; ++j){
            if(room[i][j] == 7){
                que.push(make_pair(i,j));
                // cout << i << " , " << j << endl;
            } 
        }
    }

    

    // 2-2 calculate discovery time   (safe area expansion)
    // cout << " ##initial status \n";
    //     for(int i=0; i<n; ++i){
    //         for(int j=0; j<m; ++j){
    //             cout << room[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     que_size = que.size();
    //     cout << " que size : " << que_size << "\n\n";



    int check = 0;
    int t = 0;
    while(check < num_exit && t<= 2*n + 2*m -4 ){
        t++;
        que_size = que.size();

        // cout << "q size : " << que_size << "\n";
        for(int i=0; i<que_size; ++i){
            cur_i = que.front().first;
            cur_j = que.front().second;

            if(cur_i == 0 || cur_i == n-1 || cur_j == 0 || cur_j == m-1){ // 경계에 도착한 경우 -> escape time 기록
                escape_time[cur_i][cur_j] = t;
                check ++;
            }
            arv[cur_i][cur_j] = 1;

            //adjacents
            for(int d=0; d<4; ++d){
                new_i = cur_i + di[d];
                new_j = cur_j + dj[d];
                if(new_i>=0 && new_i < n && new_j >=0 && new_j < m && room[new_i][new_j] != 1 && room[new_i][new_j] != 3 && arv[new_i][new_j]== 0){
                    room[new_i][new_j] = 7;
                    que.push(make_pair(new_i, new_j));
                }
            }
            que.pop();
        }


        // cout << "current time is : " << t << "\n";
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<m; ++j){
        //         cout << room[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // que_size = que.size();
        // cout << " que size : " << que_size << "\n\n";
    }

    // cout << "\nfinal escape time is : " << t << "\n";
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<m; ++j){
    //         cout << escape_time[i][j] << " ";
    //     }
    //     cout << "\n";
    // }




    while(!que.empty()){
        que.pop();
    }


    // 3-1 set initial fire area
    for(int i=0; i<n; ++i){
        for(int j= 0; j<m; ++j){
            if(room[i][j] == 3){
                que.push(make_pair(i,j));
                // cout << i << " , " << j << endl;
            } 
        }
    }

    // 3-2 calculate discovery time   (safe area expansion)
    // cout << "\n\n ##initial status \n";
    //     for(int i=0; i<n; ++i){
    //         for(int j=0; j<m; ++j){
    //             cout << room[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     que_size = que.size();
    //     cout << " que size : " << que_size << "\n\n";



    check = 0;
    t = 0;
    while( t<= 2*n + 2*m -4 ){
        t++;
        que_size = que.size();

        // cout << "q size : " << que_size << "\n";
        for(int i=0; i<que_size; ++i){
            cur_i = que.front().first;
            cur_j = que.front().second;

            fire_time[cur_i][cur_j] = t;
            check ++;
            f_arv[cur_i][cur_j] = 1;

            for(int d=0; d<4; ++d){
                new_i = cur_i + di[d];
                new_j = cur_j + dj[d];
                if(new_i>=0 && new_i < n && new_j >=0 && new_j < m && room[new_i][new_j] != 1 && f_arv[new_i][new_j]== 0){
                    room[new_i][new_j] = 3;
                    que.push(make_pair(new_i, new_j));
                }
            }
            que.pop();
        }


        // cout << "current time is : " << t << "\n";
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<m; ++j){
        //         cout << room[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // que_size = que.size();
        // cout << " que size : " << que_size << "\n\n";
    }

    // cout << "\nfinal escape time is : " << t << "\n";
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<m; ++j){
    //         cout << fire_time[i][j] << " ";
    //     }
    //     cout << "\n";
    // }



    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(escape_time[i][j] >= fire_time[i][j]){
                room[i][j] = -2;
            }
            else{
                room[i][j] = escape_time[i][j];
            }
        }
    }

    
    int res = INT_MAX;

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){

            // cout << room[i][j] << " ";
            if (room[i][j] == -2){
                continue;
            }
            else{
                if(room[i][j] <=res){
                    res = room[i][j];
                }
            }
        }
        // cout << "\n";
    }
    if(res != INT_MAX){
        cout << res;
    }
    else{
        cout << "IMPOSSIBLE";
    }


}

