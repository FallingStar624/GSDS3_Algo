/*
숫자 카드의 개수 N(1 ≤ N ≤ 500,000)
숫자 카드의 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다
M(1 ≤ M ≤ 500,000)
상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수도
-10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int card[500002];

int BinarySearchStart(int num){
    int st = 0;
    int en = N;
    while (st < en){
        int mid = (st+en)/2;
        if (card[mid] >= num){
            en = mid; 
        }
        else if (card[mid] < num){
            st = mid + 1;
        }
    }
    return st;
}

int BinarySearchEnd(int num){
    int st = 0;
    int en = N;
    while (st < en){
        int mid = (st+en)/2;
        if (card[mid] > num){
            en = mid;
        }
        else if (card[mid] <= num){
            st = mid + 1;
        }
    }
    return st;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; ++i){
        cin >> card[i];
    }
    sort(card, card+N);
    cin >> M;
    for (int i=0; i<M; ++i){
        int input;
        cin >> input;
        cout << - BinarySearchStart(input) + BinarySearchEnd(input) << ' ';
    }

    return 0;
}