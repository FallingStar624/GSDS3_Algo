/* 15683 감시 
- 가정 : 
게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시킴 
이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 됨.
한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. 
똑같은 수가 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
(이 문제에서 블록이 추가되는 경우는 없다)
- 문제 :
보드의 크기가 N×N 이다. 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 
최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성
*/

/* 
- 입력 : 
첫째 줄 - 보드의 크기 N (1 ≤ N ≤ 20) 
둘째 줄부터 N개의 줄 - 게임판의 초기 상태
(0은 빈 칸, 이외의 값은 모두 블록. 
2 <= 블록 (2의 제곱꼴) <= 1024). 
블록은 적어도 하나 주어진다.
- 출력 :
최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록
*/

#include <bits/stdc++.h>
using namespace std;

int N; // size of board
int ans; // list of possible 
int dir[7]; // directions for 5 times (1:left, 2:right, 3:up, 4:down)
int arr1[22][22]; // before moves
int arr2[22][22]; // after moves

void backtracking(int k);
int return_max(void);
void left_move(void);
void right_move(void);
void up_move(void);
void down_move(void);
void move(int d);
void leftright_reverse(void);
void left_rotate();
void right_rotate();
void copy_array(void);
void reset(void);

// for test :
void print_array();

int main(void){
    // receive input 
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr1[i][j];
        }
    }
    
    // backtracking
    ans = 0;
    backtracking(0);

    // print answer
    cout << ans;
    
    // for test
    // cout << '\n';
    // print_array();

    return 0;
}

int f;
void backtracking(int k){
    if (k == 5) {
        reset();
        for (int i=0; i<5; i++){
            f = dir[i];
            move(dir[i]);
            // cout << '\n';  // for test
            // print_array(); // for test
            copy_array();
            // break;

        }
        if (ans < return_max()){
            ans = return_max();
        }
        return;
    }
    int count = 0; // for test
    for (int i=1; i<5; i++){
        dir[k] = i; 
        backtracking(k+1);
        // if (k == 4) count ++; continue; // for test
        // if (count > 0) break; // for test
    }
}

void copy_array(void){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            arr1[i][j] = arr2[i][j];
        }
    }
}

int return_max(void){
    int ans = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (arr2[i][j] > ans){
                ans = arr2[i][j];
            }
        }
    }
    return ans;
}

void move(int d){ 
    if (d == 1){
        left_move();
    }
    else if (d == 2){
        right_move();
    }
    else if (d == 3){
        up_move();
    }
    else if (d == 4){
        down_move();
    }

}

void left_move(void){
    for (int i=0; i<N; i++){
        int temp[21] = {};
        int idx = 0;
        for (int j=0; j<N; j++){
            if (arr1[i][j] == 0) continue;
            else if (arr1[i][j] != 0 && temp[idx] == 0){
                temp[idx] = arr1[i][j];
                // idx += 1;
            }
            else if (arr1[i][j] != 0 && temp[idx] == arr1[i][j]){
                // if (j==0) continue;
                temp[idx++] *= 2; 
                // idx += 1;
            }
            else if (arr1[i][j] != 0 && temp[idx] != arr1[i][j]){
                temp[++idx] = arr1[i][j];
                // idx += 1;
            }
        for (int j=0; j<N; j++) arr2[i][j] = temp[j];
        }
    }
}

void right_move(void){ // 2
    left_rotate();
    left_rotate();
    left_move();
    right_rotate();
    right_rotate();
}

void up_move(void){ // 3
    left_rotate();
    left_move();
    right_rotate();
}

void down_move(void){ // 4
    right_rotate();
    left_move();
    left_rotate();
}

void right_rotate(){
  // make the copy of sticker
  int arr1_c[22][22]; 
  int arr2_c[22][22];
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      arr1_c[i][j]= arr1[i][j];
      arr2_c[i][j]= arr2[i][j];
    }
  }
  // rotate
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      arr1[i][j] = arr1_c[N-j-1][i];
      arr2[i][j] = arr2_c[N-j-1][i];
    } 
  }
}

void left_rotate(){
  // make the copy of sticker
  int arr1_c[22][22]; 
  int arr2_c[22][22];
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      arr1_c[i][j]= arr1[i][j];
      arr2_c[i][j]= arr2[i][j];
    }
  }
  // rotate
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      arr1[i][j] = arr1_c[j][N-i-1];
      arr2[i][j] = arr2_c[j][N-i-1];
    } 
  }
}

void leftright_reverse(){
    int tmp1, tmp2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp1 = arr1[i][j];
            arr1[i][j] = arr1[i][N-j];
            arr1[i][N-j] = tmp1;

            tmp2 = arr2[i][j];
            arr2[i][j] = arr2[i][N-j];
            arr2[i][N-j] = tmp2;
        }
    }
}

void reset(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // arr1[i][j] = 0;
            arr2[i][j] = 0;
        }
    }    
}

// for test :
void print_array(){
    int same = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr1[i][j] != arr2[i][j]) same *= 0;
        }
    }
    if (same == 0) {
    cout << "\n";
    cout << "this is array 1 with " << f << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "this is array 2 with " << f << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }}
    // else {cout << "skip\n";}
}