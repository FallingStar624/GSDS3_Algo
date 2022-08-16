/*
2차원 평면 위의 점 N개. 
좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력

INPUT :
- 점의 개수 N (1 ≤ N ≤ 100,000)
- 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi (-100,000 ≤ xi, yi ≤ 100,000) 
- 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
*/

#include <iostream>

using namespace std;


int N;
int xi[100002];
int yi[100002];
int xi2[100002];
int yi2[100002];

void merge(int st, int en){
  int mid = (st+en)/2;
  int ldx = st;
  int rdx = mid;
  for (int i=st; i<en; i++){
    if (ldx == mid) {
      xi2[i] = xi[rdx]; 
      yi2[i] = yi[rdx++];
    }
    else if (rdx == en){
      xi2[i] = xi[ldx]; 
      yi2[i] = yi[ldx++];
    }
    else if (xi[ldx] > xi[rdx]) {
      xi2[i] = xi[rdx]; 
      yi2[i] = yi[rdx++];
    }
    else if (xi[ldx] < xi[rdx]) {
      xi2[i] = xi[ldx]; 
      yi2[i] = yi[ldx++];
    }
    else if (xi[ldx] == xi[rdx]) {
        if (yi[ldx] > yi[rdx]) {
            xi2[i] = xi[rdx]; 
            yi2[i] = yi[rdx++];
        }
        else if (yi[ldx] <= yi[rdx]) {
            xi2[i] = xi[ldx]; 
            yi2[i] = yi[ldx++];
        }
    }
  }
  for (int i=st; i<en; i++){
    xi[i] = xi2[i];
    yi[i] = yi2[i];
  }
}

void merge_sort(int st, int en){
  if (en <= st+1) return;
  int mid = (st+en)/2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> xi[i] >> yi[i];
  }

  merge_sort(0, N);

  for (int i=0; i<N; i++){
    cout << xi[i] << ' ' << yi[i] << '\n';
  }
}
