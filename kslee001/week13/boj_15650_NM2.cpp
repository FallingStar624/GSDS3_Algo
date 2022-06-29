#include <iostream>
#include <stack>
using namespace std;
/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
*/

/* 5 3 : 
ex. 1 2 3 4 5 5 기준

1 2 3 
1 2 4
1 2 5
1 3 4
1 3 5
수가 작으면 출력하지 않는다! -> stack 활용

*/
int n, m;
int arr[10];  // 저장공간
int used[10];

stack<int> last;
int last_num = -1;

void func(int k, stack<int> &last){
    if(k==m){
        for(int i=0; i<m; ++i){
            printf("%d ", arr[i]);
        }
        printf("\n");
        if(!last.empty()){
            // printf("%d --popped from the stack\n", last.top());
            last.pop();
        }        
        return;  // base case : 출력 후 return
    }

    for(int i=1; i<=n; ++i){
        if(last.empty()){
            last.push(-1);
        }
        if( (!used[i] && i >= last.top()) ) {
            arr[k]  = i;  // i = 1 to n
            used[i] = 1;
            last.push(i);
            // printf("%d pushed into stack\n", i);
            func(k+1, last); 
            used[i] = 0;
        }
    }

    while(!last.empty()){
        // printf("------ remained stack elements :%d \n", last.top());
        last.pop();
    }
}


int main(){
    scanf("%d%d", &n, &m);
    func(0, last);
}