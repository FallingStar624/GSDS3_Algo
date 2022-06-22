#include <iostream>
#include <cmath>
using namespace std;


void func(int a, int b, int n){
    if(n == 1){     // n=1이 되었을 때(1번 기둥에 n번째 원판 하나만 남았을 때) 
                    // 1번 기둥에서 3번 기둥으로 옮긴다
        printf("%d %d\n", a, b);
        return;
    }
    func(a, 6-a-b, n-1);  // 그전까지는 1번 기둥에서 2번 기둥으로 옮긴다
    printf("%d %d\n", a,b); 

    func(6-a-b, b, n-1);  // 다 옮겨지면 2번 기둥에 있는애들을 3번 기둥으로 옮긴다.
}

int main(){
    int n; cin >>n;
    int k=n; int num = 1;  
    while(k){
        num*=2;
        k--;
    }
    printf("%d\n", num-1);
    func(1,3,n);
}
