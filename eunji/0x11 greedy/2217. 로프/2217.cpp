/*
문제 : 
N개의 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량 구하기.
k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 
각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.
모든 로프를 사용할 필요는 없다.

Input : 
N(1 ≤ N ≤ 100,000)
N개의 줄에는 각 로프가 버틸 수 있는 최대 중량 (10,000을 넘지 않는 자연수)

Output : 
로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량
*/

#include <algorithm>
#include <iostream>
using namespace std;

int N; 
int r[100002];
int answer = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N ;
    for (int i=0; i<N; i++){
        cin >> r[i];
    }

    sort(r, r+N);

    // for (int i=0; i<N; i++){
    //     cout << r[i];
    // }

    answer = r[0] * N; // 15
    int count = 0;
    for (int i=1; i<N; i++){
        count ++;
        if (answer < r[i] * (N-count)){
            answer = r[i] * (N-count);
        }
    }

    cout << answer;

    return 0;
}