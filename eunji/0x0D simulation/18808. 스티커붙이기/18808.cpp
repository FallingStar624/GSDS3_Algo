/* 
[INPUT]
노트북의 세로와 가로 : N, M (1 ≤ N, M ≤ 40)
스티커의 개수 : K(1 ≤ K ≤ 100)
스티커의 세로와 가로 : R, C (1 ≤ R, C ≤ 10)
스티커 모양 : 0은 스티커가 붙지 않은 칸을, 1은 스티커가 붙은 칸
[OUTPUT]
노트북에 스티커가 붙은 칸의 수
*/

#include <bits/stdc++.h>
// #include iostream;
using namespace std;

/* definition */
int n, m; // notebook size
int r, c, k; // sticker size & number
int nb[42][42]; // notebook 
// int nb2[42][42]; // notebook w/ stickers
int st[12][12]; // sticker

/* for test */
void printarray();
void printsticker();

/* count ones in the notebook w/ stickers */
int countones(){
  int one = 0;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      if (nb[i][j] == 1) one ++;
    }
  }
  return one;
}

/* check if the sticker is pastable in (x,y) of notebook */
bool pastable(int x, int y){
  // bool p = true;
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      if (nb[x+i][y+j] == 1 && st[i][j] == 1) {
        // p = false;
        return false;
        }
    }
  }  
  // return p;
  return true;
}

void paste(int x, int y){
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      if (st[i][j] == 1) {
        nb[x+i][y+j] = 1;
      }
    }
  }    
}

/* rotate the sticker 90 degrees clockwise */
void rotate(){
  // make the copy of sticker
  int st2[12][12]; 
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      st2[i][j]= st[i][j];
    }
  }
  // rotate
  for (int i=0; i<c; i++){
    for (int j=0; j<r; j++){
      st[i][j] = st2[r-j-1][i];
    } 
  }
  // swap r & c;
  int r2 = r;
  int c2 = c;
  r = c2;
  c = r2;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;  
  while (k>0) {
    /* save each sticker */
    cin >> r >> c;
    for (int i=0; i<r; i++){
      for (int j=0; j<c; j++){
        cin >> st[i][j];
      }
    }
    
    /* paste each sticker */
    int rotation = 0;
    bool pasted = false;
    while (1){
      for (int a=0; a<(n-r+1); a++){
        for (int b=0; b<(m-c+1); b++){
          if (pasted == true) break; 
          else if (pastable(a, b) && pasted == false) {
            paste(a, b); 
            pasted = true;
            break;
          }
         }
        }
 
      /* if not pastable, rotate the sticker */
      if (pasted == true) break; 
      rotate();
      rotation ++; 
      if (rotation == 4) break;
    }
    // printf("thie is rotation %d\n", rotation); //for test
    // printarray(); // for test
    // printsticker();

    /* repeat for all stickers */
    k--;
  }
  
  // printarray(); // for test
  cout << countones() << '\n';
  return 0;
}


/* for test */
void printarray(){
  printf("---------test---------\n");
  printf("n is %d, m is %d.\n", n, m);
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      printf("%d ", nb[i][j]);
    }
    cout << '\n';
  }
}

void printsticker(){
  printf("---------test---------\n");
  printf("r is %d, c is %d.\n", r, c);
  for (int i=0; i<r; i++){
    for (int j=0; j<c; j++){
      printf("%d ", st[i][j]);
    }
    cout << '\n';
  }
}