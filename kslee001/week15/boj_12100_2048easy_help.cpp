// boj 12100 2048 easy
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board1[21][21];
int board2[21][21];

void rotate(){ // 90도 회전
    int temp[21][21];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            temp[i][j] = board2[i][j];
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            board2[i][j] = temp[n-1-j][i];
    }
}

void tilt(int dir){
    while(dir--) rotate(); 
    for(int i=0; i<n; ++i){
        int tilted[21] = {};    // board2 기울기고 결과 저장할 변수
        int idx = 0;            // tilted 배열에서 어디에 삽입할지 가리키는 인덱스 변수
        for(int j=0; j<n; ++j){ 
            if(!board2[i][j]) continue;
            if(tilted[idx] ==0) // 삽입한 곳이 비어있으면
                tilted[idx] = board2[i][j];  //삽입
            else if(tilted[idx] == board2[i][j])  // 삽입할곳을 봤는데 같은 값이 있는 경우
                tilted[idx++] *=2;    // 두배로하고 idx ++
            else
                tilted[++idx] = board2[i][j];   // 다른 값이 충돌하면 idx ++ 한뒤에 삽입
        }
        for(int j=0; j<n; ++j) board2[i][j] = tilted[j]; // board[i][j] 에 입력
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cin >>board1[i][j];
    }

    int res = 0;
    for(int temp=0; temp<1024; ++temp){ // 최대 1024번 진행
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                board2[i][j] = board1[i][j];
            }
        }
        int brute = temp;
        for(int i=0; i<5; ++i){
            int dir = brute%4;
            brute/=4;
            tilt(dir);
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                res = max(res, board2[i][j]);
            }
        }
    }

    cout << res;
}