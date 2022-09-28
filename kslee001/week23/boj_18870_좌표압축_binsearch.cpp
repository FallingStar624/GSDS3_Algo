#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x[1000000];
vector<int> uni; // unique
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        uni.push_back(x[i]);
    }
    sort(uni.begin(), uni.end());
    
    // vector 유니크한 애들만 남기고 제거
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    
    for(int i = 0; i < n; i++)
        // vector 시작위치 찍어주어야함!!
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';

}