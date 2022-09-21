// natural num N, int K -> 이항 계수 (N K)를 10007로 나눈 나머지
// 1st row: 1<=N<=1000, 0<=K<=N

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
//bool prime;
int arr[1002][1002];
//long long ans=1;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;

    for (int i=1; i<=n; i++){
        arr[i][0] = arr[i][i] = 1;
        for (int j=1; j<i; j++){ // j=0; j<=i; j++
            //if (j==0 || i==j) arr[i][j]==1; ???????
            //else if (j==1) arr[i][j] = i;
            
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j])%10007;
            //arr[i][j] %=10007;
        }
    }

    cout<<arr[n][k];
    return 0;
}

// DP
// (n k) + (n k+1) = (n+1 k+1)
// (n k) = n/k + (n-1 k-1) = (n-1 k-1) + (n-1 k)
// https://bluebluediary.tistory.com/33
// https://littlejay.tistory.com/88?category=931940