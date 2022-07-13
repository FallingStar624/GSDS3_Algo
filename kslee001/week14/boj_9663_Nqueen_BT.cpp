#include <bits/stdc++.h>
using namespace std;

bool used1[40];
bool used2[40];
bool used3[40];

int cnt = 0;
int n;
void func(int k){
    if(k == n){
        cnt ++;
        return;
    }
    for(int i=0; i<n; ++i){
        if(used1[i] || used2 [i+k] || used3[ k-i + n-1]  ) continue;
        used1[i] = 1;
        used2[i+k] = 1;
        used3[k-i+n-1]= 1;
        func(k+1);
        used1[i] = 0;
        used2[i+k] = 0;
        used3[k-i+n-1] = 0;
    }
}

int main(){
    scanf("%d", &n);
    func(0);
    printf("%d", cnt);
}