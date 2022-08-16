// 정수 n(<11)을 1, 2, 3의 합으로 나타내는 방법의 수
// 1st row: # of test case T
// 2nd row~: n

#include <iostream>
#include <algorithm>
using namespace std;

int n[11];
int t;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    n[1]=1;
    n[2]=2;
    n[3]=4;
    for (int i=4; i<11; i++){
        n[i] = n[i-1]+n[i-2]+n[i-3];
    }

    cin>>t;
    //for (int i=0; i<t; i++){
    while(t--){
        int num;
        cin>>num;

        cout<<n[num]<<'\n';
        
    }

}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// D[4] = 1+1+1+1, 3+1, 2+1+1, 1+2+1, -> D[3]'+1'
// 1+1+2, 2+2, -> D[2]'+2'
// 1+3 -> D[1]'+1'
// D[4] = D[3]+D[2]+D[1]