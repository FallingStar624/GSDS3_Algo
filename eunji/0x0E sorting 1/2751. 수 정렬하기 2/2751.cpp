/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬

input :
1번째 줄 = N (1<=N<=1,000,000)
2번째 줄 = N개의 수 (절대값이 1,000,000보다 작거나 같은 정수, 중복없음)

*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000002];
int temp[1000002];

void merge(int st, int en){
    int mid = (st+en)/2;
    int ldx = st;
    int rdx = mid;
    for (int i=st; i<en; i++){
        if (rdx == en) temp[i] = arr[ldx++];
        else if (ldx == mid) temp[i] = arr[rdx++];
        else if (arr[ldx] <= arr[rdx]) temp[i] = arr[ldx++];
        else if (arr[ldx] > arr[rdx]) temp[i] = arr[rdx++];
    }
    for (int i=st; i<en; i++){
        arr[i] = temp[i];
    }
}

void merge_sort(int st, int en){
    if (en <= st+1) return;
    int mid = (st+en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
    }

int main(void){
    // save INPUT
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i]; 
    // MERGE sort
    merge_sort(0,N);
    // print OUTPUT
    for (int i=0; i<N; i++){
        cout << arr[i] << '\n';
    }
}