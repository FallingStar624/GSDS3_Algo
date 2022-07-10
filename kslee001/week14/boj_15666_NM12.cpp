#include <bits/stdc++.h>
using namespace std;

/*
backtracking - NM11
15665

4 2
9 7 9 1
---------
1 1
1 7
1 9
7 1
7 7
7 9
9 1
9 7
9 9

*/

int arr[10];
int used[10];
int sorted[10];
int n,m;

stack<int> last;

void input(){
    scanf("%d%d", &n,&m);
    for(int i=0; i<n; ++i){ scanf("%d", &sorted[i]);}
    sort(sorted, sorted+n);
}


void func(int k, int prev_idx){
    // BASE CASE
    if (k ==m){
        for(int i=0; i<m; ++i){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    int prev = 0;
    
    for(int i=0; i<n; ++i){ // parameter로 받은 prev idx 의 바로 다음부터 시작
        // if(used[i]) continue;           // 이미 사용된 경우 continue
        if(prev == sorted[i]) continue; // 직전 값 prev가 sorted[i] 와 같은 경우 continue
        if(last.empty()) last.push(-1);
        if(last.top() > sorted[i]) continue;
        used[i] = 1;          // used 기록
        arr[k]  = sorted[i];  // print용 arr에 현재 보고 있는 값 (sorted[i]) 입력
        prev    = sorted[i];  // prev 기록
        last.push(sorted[i]);
        func(k+1, i);         // prev의 index 넘김 
        used[i] = 0;
    }

    while(!last.empty()) last.pop();

}

int main(){
    input();
    func(0, -1);
}