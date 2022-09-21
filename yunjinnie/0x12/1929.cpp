// prime number of M<= x <=N
// 1st row: 1<=M<=N<=1,000,000, 소수는 적어도 하나 이상

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long m, n;
//bool prime;
int arr[1000002] = {0, };
int rt;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n;

    for (int i=2; i<=n; i++){
        arr[i]=i;
    }

    for (int i=2; i<=sqrt(n); i++){
        if (arr[i]==0) continue;
        for (int j=i*i; j<=n; j+=i){ //4, 6, 8, ...
            arr[j]=0;
        }

    }

    for (int num=m; num<=n; num++){
        if (arr[num]!=0){
            cout<<num<<'\n';
        }

    }

    /*
    for (int num=m; num<=n; num++){
        if (num==1) prime=0;
        else if (num==2) {
            prime=1;
            cout<<num<<'\n';
        }
        for (int j=2; j<num; j++){
            if (num%j ==0) {
                prime=0;
                break;
            }
            
            else {
                if (j==num-1){
                    prime=1;
                    //ans++;
                    cout<<num<<'\n';
                }
            }
        }
    }
    */

    return 0;
}

// 1978대로 풀면 시간초과 (10억 ms) -> 에라토스테네스의 체
// 제곱근을 기준으로 모든 인수들은 짝을 이루고 있음 -> 제곱근까지만 검사
// https://donggoolosori.github.io/2020/10/16/eratos/