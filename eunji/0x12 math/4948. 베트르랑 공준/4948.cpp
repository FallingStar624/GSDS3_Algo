/*
자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수
1 ≤ n ≤ 123,456
*/

#include <iostream>
#include <math.h>
using namespace std;

int n;
int prime[123458*2];
int IsPrime(int a);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    prime[1] = 0;
    prime[2] = 1;

    for (int i=3; i<=123458*2; i++){
        if (IsPrime(i)) prime[i] = prime[i-1] + 1;
        else prime[i] = prime[i-1];
    }

    while(1){
        cin >> n;
        if (n==0) break;
        int answer = prime[2*n] - prime[n];
        cout << answer << '\n';
    } 
    return 0;
}

int IsPrime(int num){
    if (num == 1) return 0;
    for (int i=2; i<=sqrt(num); ++i){
        if (num % i == 0) return 0;
    }
    return 1;
}


// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);


//     while(1){
//         cin >> n;
//         if (n==0) break;
//         int answer = 0;
//         for (int i=n+1; i<=2*n; i++){
//             if (IsPrime(i)) answer ++;
//         }
//         cout << answer << '\n';
//     } 

//     return 0;
// }


// int IsPrime(int num){
//     if (num == 1) return 0;
//     for (int i=2; i<=sqrt(num); ++i){
//         if (num % i == 0) return 0;
//     }
//     return 1;
// }