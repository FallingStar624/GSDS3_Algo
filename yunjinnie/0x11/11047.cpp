// 동전 N 종류 -> 합이 K가 되도록 하는 동전 개수 최솟값
// 1st row: 1<=N<=10, 1<=K<=1B
// 2nd row ~ Nth row: value 1<=Ai<=1M, i>=2일 때 Ai는 Ai-1의 배수, ascending

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[12];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    int cnt=0;

    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    for (int i=n-1; i>=0; i--){
        cnt+=k/arr[i];
        k=k%arr[i];
    }

    cout<<cnt;
    return 0;

}

// DP : min(D[i-1], D[i-2] ... ) -> O(NK), 시간초과
// greedy -> 높은 금액 동전을 최대로 먼저 사용하는 게 동전 개수 최소화
// 동전 간 배수 관계 성립하지 않아도 동작? x
// https://guiyum.tistory.com/47