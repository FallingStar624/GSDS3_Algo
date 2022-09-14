// https://www.acmicpc.net/problem/11053 가장 긴 증가하는 부분수열 DP
#include <iostream>
using namespace std;

/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 
A = {10, 20, 30, 50} 이고, 길이는 4이다.

    0) i = 1 (base case)
        dp[1] = 1 저장 후 진행 

    1) i = 2
    dp   1   
    arr 10 | 20, 10, 30, 20, 50  -> i번째 원소를 cur로 두고 cur_max=0 으로 설정
        j   cur                  -> j 인덱스를 감소해가며 최댓값 탐색
                                 -> dp[j] = dp[1] = 1이므로 cur_max = dp[1] 저장
                                 -> j가 더 작아질 수 없으므로 loop 종료
                                 -> dp[cur] = cur_max + 1 = 2 저장 후 다음 cur로 이동     

    2) i = 3
        (2-1)
    dp   1   2
    arr 10, 20 | 10, 30, 20, 50  -> i번째 원소를 cur 로 두고 cur_max=0으로 설정  
             j   cur             -> j 인덱스를 감소해가며 최댓값 탐색
                                 -> cur 가 j보다 작기 때문에 증가 수열이 성립하지 않는다
                                 -> 다음 j로 이동

        (2-2)
    dp   1   2
    arr 10, 20 | 10, 30, 20, 50  -> 
        j        cur             -> cur가 j와 같기 때문에 증가수열이 성립하지 않는다.
                                 -> j가 더 작아질 수 없으므로 loop 종료
                                 -> dp[cur] = cur_max + 1 = 1 저장 후 다음 cur로 이동
                                 


    3) i = 4
        (3-1)
    dp   1   2   1
    arr 10, 20, 10 | 30, 20, 50  -> i번째 원소를 cur 로 두고 cur_max=0으로 설정  
                j   cur          -> j 인덱스를 감소해가며 최댓값 탐색
                                 -> dp[j] = dp[1] = 1 > cur_max 
                                 -> cur_max = 1
                                 -> 다음 j로 이동
        
        (3-2)
    dp   1   2   1
    arr 10, 20, 10 | 30, 20, 50  
            j       cur          -> dp[j] = dp[2] = 2 > cur_max
                                 -> cur_max = 2
                                 -> 다음 j로 이동

        (3-3)
    dp   1   2   1
    arr 10, 20, 10 | 30, 20, 50  
        j           cur          -> dp[j] = dp[1] = 1 < cur_max
                                 -> cur_max = 2
                                 -> j가 더 작아질 수 없으므로 loop 종료
                                 -> dp[cur] = cur_max + 1 = 3 저장 후 다음 cur로 이동

    ...
    이런 방식으로 모든 i에 대해 진행하면서 최댓값 찾기 !      
    */

int arr[1001];
int dp [1001];
int res;

int main(){
    // input
    ios::sync_with_stdio(false); cin.tie(0);
    int n;  cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
    }

    dp[1] = 1; // base case
    for(int cur=2; cur<=n; ++cur){
        int cur_max = 0; // cur_max 설정
        int j = cur-1;   // j 설정 (cur의 바로 왼쪽부터 시작)

        while(j >= 1){ // j가 더 작아질 수 없을 때까지 loop 진행
            // 증가 수열이 성립할 수 없는 경우 (ex. arr[j] = 5 | arr[cur] = 1) -> continue
            if(arr[cur] <= arr[j]){
                --j;
                continue;
            } 
            // 증가 수열이 성립하는 경우 최댓값 비교하여 cur_max update  
            if(dp[j] > cur_max) 
                cur_max = dp[j];
            // 다음 j로 이동
            --j;
        }
        // while loop에서 찾은 cur_max에 1 더한 값(자기 자신)을 dp[cur]에 저장
        dp[cur] = cur_max + 1; 
        
        // 지금까지 구한 dp[cur]의 최댓값과 비교하며 res update
        if(dp[cur]>res)
            res = dp[cur];
    }

    // trivial solution
    if(n==1) cout << 1;
    // solution
    else cout << res;
}