#include <iostream>
using namespace std;



int main(){
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; ++i){scanf("%d", &arr[i]);}
    int dp [n]; fill(dp, dp+n, 1);
    int res =0;

    if(n == 1){
        printf("%d", 1); return 0;
    }
    // simple answer
    // 두번째 원소부터 탐색
    for(int i=1; i<n; ++i){
        int max = 0; // max값 초기화
        for(int j=i-1; j>=0; j--){  // 현재 원소의 바로왼쪽부터 탐색
            // 만일 지금 보고 있는 원소 (arr[i])가 
            // 왼쪽 원소 (arr[j]) 보다 크고,
            // 그 왼쪽 원소의 dp[j] 가 지금껏 저장된 max보다 크다면
            // max를 dp[j]로 업데이트  
            if(arr[i] > arr[j] && dp[j] >max){
                // printf("%d/%d : %d , %d \n", i, j, arr[i],arr[j]);
                max = dp[j];
            }
        }
        dp[i] = max+1; // 그 max값에 1 더한 값을 저장 (자기자신)
        if(dp[i]>res){
            res = dp[i];
        }
    }
    printf("%d", res);
    // printf("\n");
    // for(int i=0; i<n; ++i){printf("%d ", dp[i]);}


}