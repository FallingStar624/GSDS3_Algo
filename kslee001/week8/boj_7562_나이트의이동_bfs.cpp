#include <iostream>
#include <queue>
using namespace std;
#define Y first
#define X second


// BFS problem

/*
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
각 테스트 케이스는 세 줄로 이루어져 있다. 
첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 
체스판의 크기는 l × l이다. 
체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1


5
28
0


*/

int map[300][300];


int main(){
    int t; cin >> t ; // 3
    int n;

    int dy[8] = {2, 2, -2,-2, 1,-1,  1,-1};
    int dx[8] = {1,-1,  1,-1, 2, 2, -2,-2};
    int cy;
    int cx;
    int ny;
    int nx;

    pair<int,int> start;
    pair<int,int> target;
    pair<int,int> cur;
    pair<int,int> adj;
    queue<pair<int,int>> que;

    bool flag;

    for(int test=0; test<t; ++test){
        flag = false;


        cin >> n;  // 8
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                map[i][j] = 0;  // 체스판 0으로 init
            }
        }
        cin >> start.Y;
        cin >> start.X;
        cin >> target.Y;
        cin >> target.X;

        // cout << "\n";
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<n; ++j){
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        
        map[start.Y][start.X] = 1; // dist 설정
        que.push(start); // queue 에 넣고 시작
        while(!que.empty()){ 
            cur = que.front();  // queue 맨 첫 element 확인
            cy = cur.Y;
            cx = cur.X;
            if(cur.Y == target.Y && cur.X == target.X){
                cout << map[cur.Y][cur.X]-1 << "\n";
                while(!que.empty()){
                    que.pop();
                }
                flag = true;
                break;
            }
            que.pop();
            for(int d=0; d<8; ++d){
                adj = {cur.Y + dy[d], cur.X + dx[d]}; // adj 설정
                // cout << "adj :" << adj.Y << "," << adj.X << "\n";
                // 영역 벗어나면 continue
                if(adj.Y < 0 || adj.Y >= n || adj.X < 0 || adj.X >= n){ 
                    // cout << " - out of bound \n";
                    continue;
                }
                // 이미 방문했으면 continue
                else if(map[adj.Y][adj.X]>0){
                    continue;
                }
                // 영역 안에 있는 경우. . .
                else{
                    map[adj.Y][adj.X] = map[cur.Y][cur.X] + 1; // cur 보다 1개 많은 숫자로 dist 설정
                    que.push(adj);
                    // cout << " - set distance : " << map[adj.Y][adj.X] << "\n";
                } 
            }
        }
        while(!que.empty()){
            que.pop();
        }
        if(flag == false){
            cout << "-1\n";
        }
        // cout << "\n";
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<n; ++j){
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
        

}