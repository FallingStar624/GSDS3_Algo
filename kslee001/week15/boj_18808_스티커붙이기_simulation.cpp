#include <bits/stdc++.h>
using namespace std;
// 18808 스티커붙이기

int n,m,k; // n,m   k:스티커개수
int sn,sm; // 스티커 크기

bool used[40][40]; // 사용된 영역 표시
int stk1[40][40];  // 스티커 1
int stk2[40][40];  // 스티커 2

// 매트릭스 그려주는 디버그 함수
// template <typename T>
// void debug(T arr[][40], int n, int m){
//     printf("\n\n --debug--\n");
//     for(int i=0;i<n; ++i){
//         for(int j=0; j<m; ++j){
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }

bool oob(int y, int x){ return y<0 || y>=n || x <0 || x>=m; } // oob 체크 함수
void make_stk(int arr[][40]){ // 스티커의 크기 받아서 stk1 매트릭스에 넣어주는 함수
    scanf("%d%d", &sn, &sm);
    for(int i=0; i<sn; ++i){
        for(int j=0; j<sm; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
}
/*
Logic :
    1. check_space 
        - 현재 위치 + 스티커 크기 == OOB : return false
        - 현재 위치 내 스티커 이미 존재 : return false
        - else : return true
    2. if(check_space == true) --> attach_stk
    3. 만약 attch_stk 없이 for loop가 종료되면
        -> 90 rotate 후 재시도
*/
bool check_space(int target_stk[][40], int y, int x){ 
    // 스티커 붙일 공간 있는지 확인하는 함수 
    if(oob(y+sn-1, x+sm-1)) return false;   // OOB일때는 무조건 false
    // 주어진 범위 탐색
    for(int i=y, si=0; i<y+sn, si<sn; ++i, ++si){
    for(int j=x, sj=0; j<x+sm, sj<sm; ++j, ++sj){
        if(target_stk[si][sj] && used[i][j]) return false;
    }}
    return true;     // for loop 다 끝날때까지 이상 없으면 true 
}
void attach_stk(int target_stk[][40], bool used[][40], int y, int x){
    // 스티커 붙이는 함수
    for(int i=y, si=0; i<y+sn, si<sn; ++i, si++){
    for(int j=x, sj=0; j<x+sm, sj<sm; ++j, sj++){
        if(target_stk[si][sj]) used[i][j] = target_stk[si][sj];
    }}
}
bool func(int target_stk[][40]){
    // check_space + attach_stk 
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            // 자리 있는지 확인하고(check_space) 자리 있으면 거기에 붙이고 true반환
            if(check_space(target_stk, i, j)){
                attach_stk(target_stk, used, i, j);
                return true;
            }
        }
    }
    // 스티커 못붙이면 false 반환
    return false;
}

// source를 target에 90도 돌려서 붙여넣기
void rotate(int target[][40], int source[][40]){
    for(int i=0; i<sn; ++i){
        for(int j=0; j<sm; ++j){
            target[j][sn-i-1] = source[i][j];
        }
    }
    swap(sn, sm);
}

int result(){
    int cnt = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cnt += used[i][j];
        }
    }
    return cnt;
}


int main(){
    scanf("%d%d%d", &n,&m,&k);
    for(int idx=0; idx<k; ++idx){
        // 1. take input
        make_stk(stk1);
        if(func(stk1)) continue; // 첫 시도
        rotate(stk2, stk1);
        if(func(stk2)) continue; // 두번째 시도
        rotate(stk1, stk2);
        if(func(stk1)) continue; // 세번째 시도
        rotate(stk2, stk1);
        func(stk2);              // 네번째 시도
    }
    printf("%d", result());
}