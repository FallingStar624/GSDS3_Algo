// 소인수분해
// 1st row: 1<=N<=10,000,000

#include <iostream>
#include <algorithm>
using namespace std;

long long num;
//bool prime;
//int arr[1000002] = {0, };

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>num;

    for (int i=2; i<=num; i++){
        while (num%i==0){
            num=num/i;
            cout<<i<<'\n';
        }
    }
    return 0;

}