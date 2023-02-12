/*
1 ≤ N ≤ 10000
-10000 ≤ Ai ≤ 10000 코딩 실력
코딩 실력의 합이 0이 되는 팀
출전할 수 있는 팀을 몇개나 만들 수 있을까?
*/

#include <algorithm>
#include <iostream>
using namespace std;

int N;
int score[10002];
int answer = 0;

int Check(int a, int temp){
    int st = temp;
    int en = N-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (score[mid] < a){
            st = mid + 1;
        }
        else if (score[mid] > a){
            en = mid - 1;
        }
        else if (score[mid] == a){
            return 1;
        }
    }
    return 0;
}

int CheckS(int a, int temp){
    int st = temp;
    int en = N-1;
    while (st < en){
        int mid = (st+en)/2;
        if (score[mid] < a){
            st = mid+1;
        }
        else if (score[mid] >= a){
            en = mid;
        }
    }
    return st;
}

int CheckE(int a, int temp){
    int st = temp;
    int en = N;
    while (st < en){
        int mid = (st+en)/2;
        if (score[mid] <= a){
            st = mid+1;
        }
        else if (score[mid] > a){
            en = mid;
        }
    }
    return st;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> score[i];
    }
    sort(score, score+N);

    for (int i=0; i<=N-3; i++){
        for (int j=i+1; j<=N-2; j++){
            int target; 
            target = - score[i] - score[j];
            // cout << score[i] << ',' << score[j] << ',' << target << '\n';
            if (Check(target, j+1) == 1) {
                answer += CheckE(target, j+1) - CheckS(target, j+1) ;
                // cout << CheckS(target, j+1) << ',' << CheckE(target, j+1) << ',' << target << '\n';
            }
        }
    }

    cout << answer;
    return 0;
}


