/*
N(1 ≤ N ≤ 500,000)
M(1 ≤ M ≤ 500,000)

*/

#include <algorithm>
#include <iostream>
using namespace std;


int N, M;
int num[500002];

int check(int a){
    int st = 0;
    int en = N-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (num[mid] < a){
            st = mid + 1;
        }
        else if (num[mid] > a){
            en = mid - 1;
        }
        else if (num[mid] == a){
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
        cin >> num[i];
    }

    sort(num, num+N);

    cin >> M;
    int k;
    for (int i=0; i<M; i++){
        cin >> k;
        cout << check(k) << ' ';
    }
    
    return 0;
}