// https://www.acmicpc.net/problem/11652 카드
#include <iostream>
#include <climits>
#include <map>
using namespace std;
using lint = long long;
int n;
lint max = LONG_LONG_MAX;
lint arr[100000];
lint sorted[100000];
map<lint, lint> M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>n;
    lint input;
    for(int i=0; i<n; ++i){
        cin >>input;
        if(!M[input])
            M[input] = 1;
        else
            ++M[input];
    }
    map<lint,lint>::iterator iter;
    lint max_cnt = LONG_LONG_MIN;
    lint target;
    for(iter = M.begin(); iter != M.end(); ++iter){
        if(iter->second > max_cnt){
            max_cnt = iter->second;
            target  = iter->first;
        } 
    }
    cout << target;
}