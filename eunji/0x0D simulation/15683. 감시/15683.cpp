/* 15683 감시 
- 가정 : 
0은 빈칸, 6은 벽, 1~5는 CCTV 이며,
1번은 한쪽, 2번은 양쪽, 3번은 직각, 4번은 세 방향, 5번은 네 방향 감시한다.
CCTV는 벽을 통과하지 못하지만, CCTV는 통과할 수 있다.
- 문제 :
사무실의 크기와 상태, 그리고 CCTV의 정보가 주어졌을 때, 
CCTV의 방향을 적절히 정해서, 사각 지대의 최소 크기를 구하는 프로그램을 작성해라.
*/

/* 
- 입력 : 
첫째 줄 사무실 세로 N, 가로 M (1<=N, M<=8)
둘쨰 줄 사무실 전체 (CCTV 개수<=8)
- 출력 :
사각 지대의 최소 크기
*/

#include <bits/stdc++.h>
using namespace std;

/* functions */
int countzeros();
void backtracking(int k);
void fillaf(int x, int y, int d);
void update(int x, int y, int d);
void printaf();
void printbf();
void initialize();

/* definition */
int n, m; // room's size
int bef[10][10]; // room bef cctv operating
int af[10][10]; // room af cctv operating
int af2[10][10];
vector<pair<int,int>> cctv; // cctv's index location
int cctv_no = 0; // number of cctv
int cctv_dir[10]; // cctv's direction (1,2,3,4 = 왼,오,위,아래)
int ans = 1000 ; // answer

int main(void) {
  // SAVE INPUTS
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      cin >> bef[i][j]; // room shape bef cctv operating
      if (bef[i][j] != 0) {
        af[i][j] = 8; 
        af2[i][j] = 8;
      }
      // cout << bef[i][j] << '\n';
      if (bef[i][j] != 0 && bef[i][j] != 6){
        cctv.push_back(make_pair(i, j)); // cctv's index location
        cctv_no ++;
    }
  }
  }

  // BACKTRACKING
  backtracking(0); 

  // PRINT ANSWER
  cout << ans;
  return 0;
}

/* backtracking */ 
void backtracking(int k){
  if (k == cctv_no) {
    for (int i = 0; i<cctv_no; i++){
      fillaf(cctv[i].first, cctv[i].second, cctv_dir[i]);
      // printaf(); // for test
      // cout << cctv_no << '\n'; // for test : ok
      if (ans > countzeros()) ans = countzeros();
      // cout << ans <<'\n'; // for test
    }
    initialize();
    return;
  }

  for (int i=1; i<=4; i++){
    cctv_dir[k] = i;
    backtracking(k+1);

  }
}

// bef[x][y] = 1 2 3 4 5
// d = 1 2 3 4 (왼,오,위,아래)
void fillaf(int x, int y, int d){
  if (bef[x][y] == 1 ){
    update(x, y, d);
  }
  else if (bef[x][y] == 2){
    update(x, y, d);
    update(x, y, d+1);
  }
  else if (bef[x][y] == 3){
    update(x, y, d);   
    update(x, y, d+1); 
  }
  else if (bef[x][y] == 4){
    update(x, y, d);   
    update(x, y, d+1);
    update(x, y, d+3);       
  }
  else if (bef[x][y] == 5){
    update(x, y, d);   
    update(x, y, d+1);
    update(x, y, d+2);
    update(x, y, d+3);    
  }
  }

void update(int x, int y, int d){
  while (1) {
    if (d == 1) {
      y -= 1;
    }
    else if (d == 2) {
      y += 1;      
    }
    else if (d == 3) {
      x -= 1;         
    }
    else if (d == 4) {
      x += 1;         
    }  
    if (bef[x][y] == 6 || x < 0 || y < 0 || x >= n|| y >= m ) return;
    if (bef[x][y] != 0) continue;
    af[x][y] = 9;
  }

}

int countzeros(){
  int count = 0;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      if (af[i][j] == 0) {count++;};
    }
  }
  return count;
}

void initialize(){
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      af[i][j] = af2[i][j];
    }
  }  
}

// for test 
void printaf(){
  printf("n is %d, m is %d.\n", n, m);
  printf("This is room :");
  for (int i=0; i<n; i++){
    printf("\n");
    for (int j=0; j<m; j++){
      printf("%d", af[i][j]);
    }
  }
  cout << '\n';
}

void printbf(){
  printf("n is %d, m is %d.\n", n, m);
  printf("This is room :");
  for (int i=0; i<n; i++){
    printf("\n");
    for (int j=0; j<m; j++){
      printf("%d", bef[i][j]);
    }
  }
  cout << '\n';
}