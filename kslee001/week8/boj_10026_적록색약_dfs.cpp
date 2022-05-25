#include <iostream>
#include <stack>

#define Y first
#define X second
// DFS problem

/*

5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

*/


using namespace std;


int main(){
    int n; cin >> n;
    char pic[n][n];
    bool arv[n][n];

    /////////// Init  /////////////
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> pic[i][j];
        }
    }
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
    int ny;
    int nx;
    char RGB[3] = {'B', 'R', 'G'};
    int  res_normal[3] = {0};
    int  res_normal_final = 0;
    int  res_abnormal[3] = {0};
    int  res_abnormal_final = 0;
    stack<pair<int,int>> stk;
    pair<int,int> cur;
    int num_r;
    int num_g;
    int num_b;

    ///////////////////////////////


    // 정상일 때 'R' 'G' 'B'

    num_r = 0;
    num_g = 0;
    num_b = 0;

    
    for(int c = 0; c<3; ++c){
        char target = RGB[c];
        res_normal[c] = 0;
        // cout << "current color is : " << target << "\n";

        // 방문기록 초기화
        for(int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                arv[i][j] = false;
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                // cout << " current : " << i << " , " << j << "\n";
                if(arv[i][j]) {
                    // cout << " - already visited \n";
                    continue;
                } // 방문했으면 continue
                else if(pic[i][j] != target){  // target 이 아니라면 방문기록후 continue
                    // cout << " - not R \n";
                    arv[i][j] = true;
                    continue;
                }
                else{
                    // cout << " - found R \n";
                    stk.push({i,j});
                    while(!stk.empty()){
                        cur = stk.top(); stk.pop();
                        // cout << " - - while loop : " << cur.Y << " , " << cur.X <<  " \n";
                        arv[cur.Y][cur.X] = true; // 방문 기록
                        for(int d=0; d<4; ++d){
                            ny = cur.Y + dy[d];
                            nx = cur.X + dx[d];
                            if( ny < 0 || ny >= n || nx < 0 || nx >= n){ // 영역벗어나면 continue
                                continue;
                            }
                            else if (arv[ny][nx]) continue; // 방문했으면 continue
                            else if (pic[ny][nx] != target) continue; // R 아니면 continue
                            else {
                                stk.push({ny,nx});
                            }
                        }
                    }
                    res_normal[c] ++; // 각 RGB 클래스별로 영역 개수 계산
                }
            }
        }
    }
    
    for(int i=0; i<3; ++i){
        // cout<< RGB[i] << " nums : " << res_normal[i] << "\n";
        res_normal_final += res_normal[i];
    }



    // 색맹 Init
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(pic[i][j]== 'G'){
                pic[i][j] = 'R'; // G를 R로 바꾸기
            }
        }
    }



    // 색맹일 때   'R' / 'B'

    for(int c = 0; c<2; ++c){

        char target = RGB[c];
        res_abnormal[c] = 0;
        // cout << "current color is : " << target << "\n";
        // 방문기록 초기화

        for(int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                arv[i][j] = false;
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                // cout << " current : " << i << " , " << j << "\n";
                if(arv[i][j]) {
                    // cout << " - already visited \n";
                    continue;
                } // 방문했으면 continue
                else if(pic[i][j] != target){  // target 이 아니라면 방문기록후 continue
                    // cout << " - not target \n";
                    arv[i][j] = true;
                    continue;
                }
                else{
                    // cout << " - found target \n";
                    stk.push({i,j});
                    while(!stk.empty()){
                        cur = stk.top(); stk.pop();
                        // cout << " - - while loop : " << cur.Y << " , " << cur.X <<  " \n";
                        arv[cur.Y][cur.X] = true; // 방문 기록
                        for(int d=0; d<4; ++d){
                            ny = cur.Y + dy[d];
                            nx = cur.X + dx[d];
                            if( ny < 0 || ny >= n || nx < 0 || nx >= n){ // 영역벗어나면 continue
                                continue;
                            }
                            else if (arv[ny][nx]) continue; // 방문했으면 continue
                            else if (pic[ny][nx] != target) continue; // R 아니면 continue
                            else {
                                stk.push({ny,nx});
                            }
                        }
                    }
                    res_abnormal[c] ++; // R, B 클래스별로 영역 개수 계산
                }
            }
        }
    }

    for(int i=0; i<2; ++i){
        // cout<< RGB[i] << " nums : " << res_abnormal[i] << "\n";
        res_abnormal_final += res_abnormal[i];
    }

    cout << res_normal_final << "\n";
    cout << res_abnormal_final << "\n";

}

