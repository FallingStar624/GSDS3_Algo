/*
1 ≤ N ≤ 1,000,000
-10^9 ≤ Xi ≤ 10^9
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int x[1000005];
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
