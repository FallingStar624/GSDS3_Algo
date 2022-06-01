// DFS problem
// https://www.acmicpc.net/problem/2583

/*
5 7 3    박스크기(세로, 가로) / in box 개수 
0 2 4 4  in box 1 coord
1 1 2 5  in box 2 coord
4 0 6 2  in box 3 coord



5 7 3
0 2 4 4
1 1 2 5
4 0 6 2

3
1 7 13

*/

#include <iostream>
#include <stack>
using namespace std;

typedef pair<int,int> Coord; // 좌표 저장 ( x, y )
typedef pair<Coord, Coord> Box; // 좌표 두개 저장 (left coord(x,y), right coord(x,y))
#define Y first
#define X second


int main(){

    int n,m,k; cin >> n >> m >>k;

    // map, arrival 정의
    int map[n][m];
    int arv[n][m];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            map[i][j] = 0;         // INIT map
            arv[i][j] = 0;         // INIT arv
        }
    }

    // k개의 사각형 범위 정의
    int x1, y1, x2, y2;
    for(int i=0; i<k; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y=y1; y<y2; ++y){
            for(int x = x1; x<x2; ++x){
                map[y][x] = 1;
            }
        }
    }

    // cout << "\n";
    // ///////////////  for debugging
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<m; ++j){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // ///////////////
    // cout << "\n";



    Coord cur;
    Coord adj;
    stack<Coord> stk;
    stack <int> area;
    
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
    int ny;
    int nx;

    int num_area = 0;
    int cur_area;
    // DFS
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            // 모든 지점에 대해 탐색
            if(arv[i][j]){ // 방문 한 경우에는 더 안들어가고 continue
                continue;
            }
            else if (map[i][j]){ // 1인경우 방문 표시하고 continue
                arv[i][j] = 1;
                continue;
            }
            else{  // 0인 경우 dfs
                stk.push({i,j});
                num_area ++;  // 0으로된 구역을 찾았으니 num_area ++
                cur_area = 0; // 넓이 초기화
                while(!stk.empty()){ // DFS
                    cur = stk.top(); stk.pop(); // DEQUE from the stack
                    if(arv[cur.Y][cur.X]){      // stack이 하나씩 빠지면서 이미 방문한 곳이 발생할 수 있음 : continue 
                        continue;
                    }
                    arv[cur.Y][cur.X] = 1;  // 방문표시
                    cur_area ++; // 한칸씩 탐색할 때마다 넓이 ++
                    
                    for(int d=0; d<4; ++d){ // 인접 노드 검사
                        adj = { cur.Y + dy[d], cur.X + dx[d] };
                        if(adj.Y < 0 || adj.Y >= n || adj.X < 0 || adj.X >= m){
                            continue;
                        }
                        else if (arv[adj.Y][adj.X]){ // 이미 방문된 경우 continue
                            continue;
                        }
                        else if (map[adj.Y][adj.X]){
                            arv[adj.Y][adj.X] = 1; // 방문 표시하고 continue
                            continue;
                        }
                        else{
                            stk.push({adj.Y, adj.X}); // 조건에 맞으면 push
                        }
                    }
                }
                if(cur_area){ // cur_area가 0이 아니라면
                    area.push(cur_area); // area stack에 현재 넓이 저장
                }
            }
        }
    }

    int area_array[num_area];
    for(int i=0; i<num_area; ++i){
        area_array[i] = area.top();
        area.pop();
    }

    int key;
    int left;
    for(int i=1; i<num_area; ++i){
        // printf(" -- current value : %d\n", area[i]);
        key =  area_array[i];
        left = i-1;
        
        while(left>=0 && key<area_array[left]){
            // printf("   -- current left value : %d / leftidx = %d \n", area[left], left);
            area_array[left+1] = area_array[left];
            left--;
        }
        area_array[left+1] = key;
        // printf("      -- current array status : ");
        // for(int j=0; j<k; ++j){
        //     printf(" %d", area[j]);
        // }
        // printf("\n");
    }


    // print output
    printf("%d\n", num_area);
    for(int i=0; i<num_area; ++i){
        printf("%d ", area_array[i]);
    }

    

}