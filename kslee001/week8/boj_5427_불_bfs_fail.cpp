#include <iostream>
#include <queue>
using namespace std;

/*
상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.

매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 
벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다. 
상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 
상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.

빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.




첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.

각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)

다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.

'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불
각 지도에 @의 개수는 하나이다.


5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###


2
5
IMPOSSIBLE
IMPOSSIBLE
IMPOSSIBLE


*/

typedef pair<int,int> pii;
#define Y first
#define X second

char map[1000][1000];
int f_arv[1000][1000];
int s_arv[1000][1000];
queue<pii> safe;
queue<pii> fire;
pii cur;



int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int ny;
int nx;

bool flag;


int main(){
    int t; cin >> t;
    int w, h;
    char input; 
    for(int test=0; test<t; test++){
        while(!safe.empty()){
            safe.pop();
        }
        while(!fire.empty()){
            fire.pop();
        }

        cin >> w >> h;
        flag = false;

        // init
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                s_arv[i][j] = 0;
                f_arv[i][j] = 0;
            }
        }
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
               cin >> input;
               map[i][j] = input;
               if(input == '@'){
                   if(i == 0 || i == h-1 || j == 0 || j == w-1){ // 시작지점이 가장자리라면 break
                    if(!flag){
                        cout << "1\n";
                        flag = true;
                    }
                   }
                   safe.push({i,j});
                   s_arv[i][j] = 1;   // 방문 기록
               } 
               else if(input == '*'){
                   fire.push({i,j});
                   f_arv[i][j] = 1;   // 방문 기록
               }
            }
        }
        if(flag) break;

        while(!fire.empty()){
            if(flag) break;
            cur = fire.front();
            fire.pop();
            for(int d=0; d<4; ++d){
                ny = cur.Y + dy[d];
                nx = cur.X + dx[d];

                // 범위 여부
                if(ny <0 || ny >= h || nx < 0 || nx >= w){
                    continue;
                }
                // 방문 여부
                else if(f_arv[ny][nx]){
                    continue;
                }
                // 벽 여부
                else if(map[ny][nx] == '#'){ 
                    continue;
                }
                // (방문 안된 곳이라면 push])
                else{
                    f_arv[ny][nx] = f_arv[cur.Y][cur.X] + 1; // 방문기록
                    fire.push({ny,nx});
                }
            }
        }

        while(!safe.empty()){
            if(flag) break;
            cur = safe.front();
            safe.pop();

            for(int d=0; d<4; ++d){
                ny = cur.Y + dy[d];
                nx = cur.X + dx[d];

                // 범위 여부
                if(ny <0 || ny >= h || nx < 0 || nx >= w){
                    cout << s_arv[cur.Y][cur.X] << "\n";
                    flag = true;
                    break;
                }
                // 방문 여부
                else if(s_arv[ny][nx]){
                    continue;
                }
                // 벽 여부
                else if(map[ny][nx] == '#'){ 
                    continue;
                }
                // 불이 먼저 도착했는지 여부
                else if(f_arv[ny][nx] < s_arv[cur.Y][cur.X]+1){
                    continue;
                }
                else{
                    s_arv[ny][nx] = s_arv[cur.Y][cur.X] + 1;
                    safe.push({ny,nx});
                }
            }
        }

        if(!flag) cout << "IMPOSSIBLE\n"; // 출력 (fail)




    }

}