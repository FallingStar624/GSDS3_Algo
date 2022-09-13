// 1<=N<=100,000 ropes, 여러 개 병렬 연결하면 중량 나눌 수 있음
// k ropes, weight w -> 각각 w/k만큼 걸림 ... 들어올릴 수 있는 최대 중량
// 1st row: N
// 2nd row ~ N+1th row: 최대 중량 <= 10,000

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int w[100002];
int ans=0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    
    for (int i=0; i<n; i++){
        cin>>w[i];
    }

    sort(w, w+n); // 오름차순
    for (int i=0; i<n; i++){
        ans = max(w[i]*(n-i), ans);
    }

    cout<< ans;
    return 0;

}


// 모든 로프 조합 -> O(2^n)
// 가장 중량 큰 로프 선택 : sort 후 least weight * (n-idx)의 최댓값
// 3 / 5 10 15 -> 5*3 = 15, 10*2 = 20, 15*1 = 15