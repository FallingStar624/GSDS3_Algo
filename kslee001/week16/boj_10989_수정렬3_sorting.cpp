#include <iostream>
#include <map>
using namespace std;


map<int, int> cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int n; cin >>n;
    int input;
    int max = 0;
    for(int i=0; i<n; ++i){
        cin >>input;
        if(!cnt[input]) cnt[input]=1;
        else ++cnt[input];

        if(max < input) max = input;
    }
    for(int i=1; i<=max; ++i){
        if(cnt[i]){
            for(int j=0; j<cnt[i]; ++j){
                cout << i << "\n";
            }
        }
    }
}