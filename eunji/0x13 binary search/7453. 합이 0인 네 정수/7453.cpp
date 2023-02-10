/*
1 ≤ N ≤ 10000
-10000 ≤ Ai ≤ 10000 코딩 실력
코딩 실력의 합이 0이 되는 팀
출전할 수 있는 팀을 몇개나 만들 수 있을까?
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
long long score[100002];
int answer = 0;

vector<int> temp, uni;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; ++i){
        cin >> x[i];
        temp.push_back(x[i]);
    }

    sort(temp.begin(), temp.end());

    uni.push_back(temp[0]);
    for (int i=1; i<N; i++){
        if (temp[i-1] != temp[i]){
            uni.push_back(temp[i]);
        }
    }
    for (int i=0; i<N; i++){
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
     }


    return 0;
} 


int check(long long a, int temp){
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


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        int answer =0;
        for (int k=0; k<4; k++) {
            cin >> score[i];
        }
        sort(score, score+N);
        for (int i=0; i<=N-4; i++){
            for (int j=i+1; j<=N-3; j++){
                for (int z = j+1; z <= N-2; z++){
                    int target; 
                    target = - score[i] - score[j] - score[z];
                    // cout << score[i] << ',' << score[j] << ',' << target << '\n';
                    if (check(target, j+1) == 1) {
                        answer ++;
                        // cout << 'o' << score[i] << ',' << score[j] << ',' << target << '\n';
                    }
                }

            }
        }
        answer ++;
    }
    // sort(score, score+N);



    cout << answer;
    return 0;
}