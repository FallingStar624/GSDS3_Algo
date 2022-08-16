/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬
메모리 제한 중요

input :
1번째 줄 = N (1<=N<=1,000,000)
2번째 줄 = N개의 수 (절대값이 1,000,000보다 작거나 같은 정수, 중복없음)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int temp;
int arr[100002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i<N; i++){
        cin >> temp;
        arr[temp] ++;
    }

    for (int i=0; i<100002; i++){
        if (arr[i] == 0) continue;
        else {
            for (int j=0; j<arr[i]; j++){
                cout << i << '\n';
            }
        }
    }
    return 0;
}
