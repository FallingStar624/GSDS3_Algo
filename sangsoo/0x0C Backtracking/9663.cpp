#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;
bool isused1[16]; // c
bool isused2[30]; // r+c
bool isused3[30]; // r-c+n-1

void func(int r){
    if (r==n){
        cnt++;
        return;
    }
    for(int c=0; c < n; c++){
        if(!((isused1[c])+(isused2[r+c])+(isused3[r-c+n-1]))){
            isused1[c] = 1; isused2[r+c] = 1; isused3[r-c+n-1] = 1;
            func(r+1);
            isused1[c] = 0; isused2[r+c] = 0; isused3[r-c+n-1] = 0;
        }
    }

}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
}