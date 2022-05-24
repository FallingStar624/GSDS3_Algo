#include <iostream>
#include <stack>
using namespace std;


/*
어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라.
단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 
가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 
그림의 넓이란 그림에 포함된 1의 개수이다.
*/

/*
첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다. 
두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. 
(단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)
*/

/*
첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 
단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.
*/

/* 
input

    6 5
    1 1 0 1 1
    0 1 1 0 0
    0 0 0 0 0
    1 0 1 1 1
    0 0 1 1 1
    0 0 1 1 1

*/


int main(){
    int n, m; cin >> n >> m;
    int h = n+2;
    int w = m+2;
    int picture[h][w];
    int arrived[h][w] = {0};

    int new_i;
    int new_j;

    int new_new_i;
    int new_new_j;


    stack<pair<int,int>> adj;


    // initialize
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            if(i == 0 || i == h-1 || j == 0 || j == w-1){
                picture[i][j] = 0;
            }
            else{
                cin >> picture[i][j];
            }
        }
    }


    // objectives
    int cur_area=0;
    int max_area=0;
    int num_islands=0;

    // search
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            cur_area = 0;       // initialize current island's area

            // case 1 : already arrived
            if(arrived[i][j] == 1){
                continue;
            }
            // case 2 : pic == 0
            else if(picture[i][j] == 0){
                arrived[i][j] = 1; // record arrival
                continue;
            }
            // case 3 : not arrived and pic == 1 (search begin)
            else{
                arrived[i][j] = 1;  // record arrival
                num_islands ++;     // add the number of islands
                cur_area ++;       // plus current islands's area

                // push adj position
                adj.push(make_pair(i, j+1));
                adj.push(make_pair(i, j-1));
                adj.push(make_pair(i+1, j));
                adj.push(make_pair(i-1, j));

                while(!adj.empty()){
                    // new position
                    new_i = adj.top().first;
                    new_j = adj.top().second;
                    // dfs case 0 : not picture area (wrong index)
                    if(new_i < 0 || new_i > h-1 || new_j < 0 || new_j > w-1){
                        adj.pop(); // pop current position
                        continue;
                    }
                    // dfs case 1 : already arrived
                    else if (arrived[new_i][new_j] == 1){
                        adj.pop(); // pop current position
                        continue;
                    }
                    // dfs case 2 : pic ==0
                    else if (picture[new_i][new_j] == 0){
                        arrived[new_i][new_j] = 1; // record arrival
                        adj.pop(); // pop current position
                        continue;
                    }
                    // dfs case 3 : not arrived and pic == 1 (search begin)
                    else{
                        arrived[new_i][new_j] = 1; // record arrival
                        adj.pop(); // pop current position
                        cur_area ++;
                        adj.push(make_pair(new_i + 1, new_j));
                        adj.push(make_pair(new_i - 1, new_j));
                        adj.push(make_pair(new_i, new_j +1));
                        adj.push(make_pair(new_i, new_j -1));  // add new adjacent coordinates.
                    }
                }

                if(cur_area >= max_area){
                    max_area = cur_area;
                }
            }

        }
    }

    cout << num_islands << "\n";
    cout << max_area;


}
