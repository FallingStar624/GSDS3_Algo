// N : sum of ith ~ jth num
// 1st row: # of num N & 합 구하는 횟수 M
// 2nd row: list of num
// 3rd row ~ Mth row: [i, j]
// num <=1000, 1<=N, M<=100000

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int lst[100001];
int s[100001]; // 100000 틀림

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>n >>m;
    s[0] = 0;

    for (int i=1; i<=n; i++){
        cin>>lst[i];
        //int a, b;
        //cin>> a>> b;
        s[i] = s[i-1]+lst[i];

        //for (int j=a; j<=b; j++){
          //  cout<< s[j]-s[i-1] << '\n'; 
        //}
    }
    while(m--){
        int a, b;
        cin >> a>> b;
        cout << s[b] - s[a-1] << '\n';
        }

}

// 출력 초과

// use prefix sum
// A[i]+ ... + A[j] : O(NM)
// D[i] = A[1]+ ... + A[i]
// D[i] = D[i-1]+A[i] 
// -> D[j]-D[i-1] : O(1)
