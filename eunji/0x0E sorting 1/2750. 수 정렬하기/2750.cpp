/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬

input :
1번째 줄 = N (1<=N<=1000)
2번째 줄 = N개의 수 (절대값이 1000보다 작거나 같은 정수, 중복없음)

*/

#include <algorithm>
#include <iostream>
using namespace std;

int N;
int arr[1002];

void sort(void){
    for (int i=0; i<N; i++){
        for (int j=i; j<N; j++){
            if (arr[j] < arr[i]) swap(arr[j], arr[i]);
        }
    }
}

int main(void){
    // save INPUT
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }

    // SORT
    sort();

    // print OUTPUT
    for (int i=0; i<N; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}