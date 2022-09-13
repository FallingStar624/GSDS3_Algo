// 최대 이익 (largest Pi)
// 1st row: 1<=N<=1,500,000
// 2nd row ~ nth row: 1<=Ti<=50 (기간), 1<=Pi<=1000 (금액)

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[1500002];
long long p[1500002];
long long d[1500002]; //= {0,}; // 최대 이익 저장

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

// ?