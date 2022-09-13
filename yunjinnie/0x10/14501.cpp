// 최대 이익 (largest Pi)
// 1st row: 1<=N<=15
// 2nd row ~ nth row: 1<=Ti<=5 (기간), 1<=Pi<=1000 (금액)

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[16];
int p[16];
int d[16]; //= {0,}; // 최대 이익 저장

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for (int i=1; i<=n; i++){
        cin>>t[i]>>p[i];
    }

    int day;
    for (int i=n; i>=1; i--){ // range check
        day = t[i]; //5->2, 6->4
        if (day>n+1-i){ //2, 1 // range - why n+1? 조건?
            d[i] = d[i+1]; // skip
        }
        else {
            d[i] = max(d[i+1], d[i+day]+p[i]);
        }
    }
    
    cout<<d[1];
    return 0;

}

// t -> index jump
// 이전 연산값 저장 후 재사용
// 6, 7 불가 -> dp 거꾸로 볼 것
// https://velog.io/@sj-lee33/%EB%B0%B1%EC%A4%80-14501%EB%B2%88-%ED%87%B4%EC%82%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-c-%ED%92%80%EC%9D%B4