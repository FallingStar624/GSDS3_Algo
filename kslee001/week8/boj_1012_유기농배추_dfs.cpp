#include <iostream>
#include <stack>

// DFS problem

using namespace std;

/*
차세대 영농인 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다. 
농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요하기 때문에, 
한나는 해충 방지에 효과적인 배추흰지렁이를 구입하기로 결심한다. 
이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 
특히, 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 
그 배추들 역시 해충으로부터 보호받을 수 있다. 
한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있는 것이다.

한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어 놓았다. 
배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 
서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다. 
예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다. 
0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.

1	1	0	0	0	0	0	0	0	0
0	1	0	0	0	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	1	1	0	0	0	1	1	1
0	0	0	0	1	0	0	1	1	1


입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 

그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 
배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 

그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 
그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 
두 배추의 위치가 같은 경우는 없다.

*/

#define Y first
#define X second

int main(){
    int t; cin >> t;  // # of test case
    int m, n;   // n :세로길이 , m:가로길이
    int k;     // 배추 개수
    int x, y;           // input으로 들어올 배추의 좌표

    // cout << "t : " << t << "  / n : " << n << "  / m : " << m << " / k : " << k  << "\n";

    //




    int res;
    for(int test=0; test<t; ++test){
        cin >> m >> n >> k;
        // cout << " m : "<< m << " / n : " << n << " / k : "<< k << "\n";
        res = 0;

        int map[n][m];
        int arv[n][m];
        stack<pair<int,int>> stk;

        int dy[4] = {1,0,-1,0};
        int dx[4] = {0,1,0,-1};
        pair<int,int> cur;
        pair<int,int> adj;
        // init 1 : map
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                map[i][j] = 0;
                arv[i][j] = 0;
            }
        }
        // init 2 : 배추
        for(int b = 0; b<k; ++b){
            cin >> x >> y;
            map[y][x] = 1;
        }

        // search : DFS
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                // base case
                if(arv[i][j]){
                    continue;      // 이미 방문한 곳이면 continue
                }
                else if(map[i][j] == 0){
                    arv[i][j] = 1; // 방문한 곳은 아닌데 0 지역이면 방문 표시하고 continue
                    continue;
                }
                else{ // 방문 안한 1 지역 -> DFS

                    // cout << " # DFS start : " << i << ", " << j << "\n";
                    res ++; // 개수 추가하기
                    stk.push({i,j}); // DFS 스택에 넣고 서치 시작하기
                    while(!stk.empty()){
                        cur = stk.top(); stk.pop();
                        // if(arv[cur.Y][cur.X]==1) continue;
                        // cout << " cur : " << cur.Y << ", " << cur.X << "\n";
                        arv[cur.Y][cur.X] = 1; // 방문 표시하기 
                        for(int d=0; d<4; ++d){
                            adj = {cur.Y + dy[d], cur.X + dx[d]};
                            // 영역 벗어났으면 continue
                            if(adj.Y < 0 || adj.Y >= n || adj.X < 0 || adj.X >= m){ 
                                continue;
                            }
                            // 이미 방문했으면 continue
                            else if(arv[adj.Y][adj.X] == 1) continue;
                            // 섬이 0이면 방문 표시하고 continue
                            else if(map[adj.Y][adj.X] == 0){
                                arv[adj.Y][adj.X] = 1;
                                continue; 
                            }
                            stk.push(adj); // 인접지역(4곳) 스택에 넣기
                        }    
                    }
                }
            }
        }
        cout << res << "\n"; 
    }







}
