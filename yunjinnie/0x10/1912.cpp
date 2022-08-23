// 수열 길이: n, 연속된 몇 개의 수 선택 -> 최대 합
// 1st row: 1<=n<=100,000
// 2nd row: 수열 (-1000<=num<=1000)

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[100002];
int num[100002];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    //d[1]=;
    for (int i=1; i<=n; i++){
        cin>>num[i];
        d[i] = num[i];
    }
    int s = num[1];
    for (int i=2; i<=n; i++){
        d[i] = max(d[i-1]+num[i], d[i]); // d[i-1]+d[i] (o) -> 연산이 먼저이므로, num[i] (o)
        if (d[i]>s) s = d[i]; // 없으면 update 안됨
    }
    cout << s;
    return 0;

}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// 첫 번째 원소부터 더해가면서 비교해보기
// 입력으로 주어지는 수열 저장하는 배열과 최댓값 저장하는 배열 따로 설정
// d[i] = max(d[i-1] (직전 최대 연속합)+d[i], d[i]);
// 어느 지점부터 어느 지점까지를 연속합으로 택하느냐
// https://mtoc.tistory.com/41
