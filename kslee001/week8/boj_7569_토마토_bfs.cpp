#include <iostream>
#include <queue>
#include <tuple>
using namespace std;


// bfs

/*
5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1

-1

5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0

4

4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-1 -1 -1 -1
1 1 1 -1

0


*/


int main(){
                                        //// init ////
    int x,y,z; cin >> x >> y >> z;
    int box[z][y][x];   // for recording status
    int arv[z][y][x];   // for recording arrival 
    queue<tuple<int,int,int>> que;
    tuple<int,int,int> cur;
    tuple<int,int,int> adj;

    int input;
    for(int k=0; k<z; ++k){
        for(int i=0; i<y; ++i){
            for(int j=0; j<x; ++j){
                cin >> input;
                box[k][i][j] = input;
                if(input == 1){
                    arv[k][i][j] = 1;   // 시작점은 1로 initialize -> 이미 방문한 것으로 시작
                    cur = {k,i,j};
                    que.push(cur);  // 시작점 push
                }
                else if (input == -1){
                    arv[k][i][j] = -1;  // 벽은 -1로intialize
                }
                else{
                    arv[k][i][j] = 0;   // 0으로 initialize            
                }
            }
        }
    }


                                        //// init ////

    //                                     // for debugging
    // for(int k=0; k<z; ++k){
    //     for(int i=0; i<y; ++i){
    //         for(int j=0; j<x; ++j){
    //             cout << box[k][i][j] << " ";
    //         }
    //     cout << "\n";
    //     }
    // }
    //                                     // for debugging


    int dz[2] = {1,-1};
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
    int cur_z, cur_y, cur_x;
    int new_z, new_y, new_x;
    int k, i, j;

    // 처음부터 꽉 차 있나?
    int cnt = 0;
    for(int k=0; k<z; ++k){
        for(int i=0; i<y; ++i){
            for(int j=0; j<x; ++j){
                if( box[k][i][j] == 1 || box[k][i][j] == -1 ){
                    cnt ++;
                }
            }
        }
    }
    if (cnt == z*y*x){
        cout << 0;
        return 0;
    }



    // BFS
    int idx = 0;
    while(!que.empty()){
        idx ++;
        cur = que.front(); // 큐 하나씩 다 보기
        que.pop();

        // 현재 좌표
        cur_z = get<0>(cur); 
        cur_y = get<1>(cur); 
        cur_x = get<2>(cur);

        // 1) 우선 y,x 축 방향으로 살펴보기
        for(int d=0; d<4; ++d){
            // 새 좌표 (y, x)
            new_y = cur_y + dy[d];
            new_x = cur_x + dx[d];

            // 방문 여부 확인하기 
            if(new_y < 0 || new_y >= y || new_x < 0 || new_x >= x){ // 영역  벗어난 경우
                continue;
            }
            else if(arv[cur_z][new_y][new_x]){
                continue;
            }
            else if(box[cur_z][new_y][new_x] == -1){                // box 값이 -1 인경우
                continue;
            }
            else{
                arv[cur_z][new_y][new_x] = arv[cur_z][cur_y][cur_x] + 1; // 방문 기록
                que.push(make_tuple(cur_z, new_y, new_x));
            }
        }
        // 2) z 방향으로 살펴보기
        for(int h=0; h<2; ++h){
            // 새 좌표 (z)
            new_z = cur_z + dz[h];

            // 방문 여부 확인하기
            if( new_z <0 || new_z >= z){   // 영역 벗어난 경우
                continue;
            }
            else if(arv[new_z][cur_y][cur_x]){
                continue;
            }

            else if(box[new_z][cur_y][cur_x] == -1){ // box 값이 -1 인경우
                continue;
            } 
            else{
                arv[new_z][cur_y][cur_x] = arv[cur_z][cur_y][cur_x] + 1;  // 방문 기록
                que.push(make_tuple(new_z, cur_y, cur_x));
            }
        }

        // // for debugging
        // cout <<"\n # "<< idx << "-th bfs \n";
        // for(int k=0; k<z; ++k){
        //     // if(k == 0 ) continue;
        //     cout << "\n" << k<< "-th floor\n";
        //     for(int i=0; i<y; ++i){
        //         for(int j=0; j<x; ++j){
        //             cout << arv[k][i][j] << " ";
        //         }
        //     cout << "\n";
        //     }
        // }

    }


    bool flag = false;
    int max_dist = 0;

    // 방문 안 된 곳이 있을까?
    for(int k=0; k<z; ++k){
        if(flag) break;
        for(int i=0; i<y; ++i){
            if(flag) break;
            for(int j=0; j<x; ++j){
                if(arv[k][i][j] == 0){
                    flag = true;
                    break;
                }
                else if(max_dist <= arv[k][i][j]){
                    max_dist = arv[k][i][j];
                }
            } 
        }
    }



    if(flag){
        cout << -1;
    }
    else{
        cout << max_dist - 1;
    }


}