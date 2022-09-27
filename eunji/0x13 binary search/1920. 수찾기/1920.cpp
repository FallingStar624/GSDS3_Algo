/*
N개의 정수 안에 X가 존재하는가?
N(1<=N<=100000)개의 정수 A
M(1<=M<=100000)개의 정수 X
정수들은 -2^31보다 크거나 같고 2^31보다 작음
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100002];

int check(int a){
    int st = 0;
    int en = N-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (a < A[mid]){
            en = mid - 1;
        }
        else if (A[mid] < a){
            st = mid + 1;
        }
        else if (a == A[mid]){
            return 1;
        }
    }
    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    // for (int i=0; i<N; i++){
    //     cout << A[i];
    // }
    cin >> M;

    for (int i=0; i<M; i++){
        int X;
        cin >> X;
        cout << check(X) << '\n'; 
    }

    return 0;

}

