// p(N) : 나선에 있는 정삼각형의 가장 긴 변의 길이
// 1st row: # of test case T
// 2nd row~: 1<=N<=100

#include <iostream>
#include <algorithm>
using namespace std;

long long t, n;
long long p[102] = {0, 1, 1, 1, 2, 2, }; // idx 0 to 5

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    
    for (int i=1; i<=t; i++){
        cin>>n;
        for (int j=6; j<=n; j++){
        // if (p[n==0]) -> func return으로 update하는 경우
            p[j] = p[j-1]+p[j-5]; // not n
        }
        cout<<p[n]<<'\n';
    }

    return 0;

}

// 1, 1, 1, 2*, 2, 3*, 4*, 5*, 7*, 9*, 12*, 16*, 21 ...
// 1+1, 1+2, 1+3, 1+4, 2+5, 2+7, 3+9, 4+12
// p(n) = p(n-1)+p(n-5)
// p(n) = p(n-3)+p(n-2)
// fibonacci -> long long
// https://mtoc.tistory.com/44