// x, y <= M, N
// 연도 표시 <x:y>
// x<M -> x' = x+1 else x'=1, y<N -> y' = y+1 else y'=1
// <M:N> : the last
// 1st row: T
// 2nd row ~ n+1th row: M, N, x, y (1<=M, N<=40,000, 1<=x<=M, 1<=y<=N)
// 유효하지 않으면 -1 출력
// <1:1> <2:2> <3:3> ... <10:10> <1:11> <2:12> <3:1> ... <10:12>

#include <iostream>
#include <algorithm>
using namespace std;

int t;
//bool prime;
//int arr[1000002] = {0, };

// euclid algorithm
int gcd(int a, int b){
    // swap
    if (a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (b>0){
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
} // or recursive -> if b==0 return a; else return gcd(a, a%b);

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;

    int m, n, x, y;
    int ans=1;

    while(t--){
        cin>>m>>n>>x>>y;
        int lim = lcm(m, n);
        //if (x==m) 1로 설정? loop 1st

        // 가능한 연도 값에서 search
        for (int i=x; i<=lim; i+=m){
            /*
            if (i==m) {
                i=1;
                ans++;
            }
            else if (j==n) {
                j=1;
                ans++;
            }
            else if (i==x && j==y) cout<<ans<<'\n'; */
            // x*m
            int j = i%n;
            //if (j==0) j = n;
            if (j==y) {
                ans = i;
                break;
            }
            else ans = -1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

// 1씩 증가시키면 시간초과
// 종말의 해 : N, M의 최소공배수 (마지막 해)
// x: 연도%m, y: 연도%n
// https://yhwan.tistory.com/17
// https://blockdmask.tistory.com/53
// https://96glory.tistory.com/35
// https://hibee.tistory.com/107
// m * loop + x = 연도