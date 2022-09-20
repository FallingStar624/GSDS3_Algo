// # of prime number in N
// 1st row: #, N<=100
// 2nd row: number list, each<=1000

#include <iostream>
#include <algorithm>
using namespace std;

int n;
// int arr[1002]; // 굳이 array로 받을 필요 없음
bool prime;
int ans=0;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    int num;

    for (int i=0; i<n; i++){
        cin>>num;
        if (num==1) prime=0;
        else if (num==2) {
            prime=1;
            ans++;
        }
        for (int j=2; j<num; j++){
            if (num%j ==0) {
                prime=0;
                break;
            }
            
            else {
                if (j==num-1){
                    prime=1;
                    ans++;
                    //cout<<num;
                }
            }
        }
    }
    cout<<ans;
    return 0;
    
}

// 1과 자기자신
// 에라토스테네스의 체 -> 커서 한 칸씩 옮기면서 그 수의 배수인 다른 수들을 모두 false로 만들어줌
// bool type: 1 byte, vector<bool>: 1 bit ... 최적화 (vector<int>나 bool보다) -> O(NloglogN)
// 소인수분해
// https://codesyun.tistory.com/63