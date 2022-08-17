#include <iostream>
#include <algorithm>
using namespace std;

int d[1005][4];
int cost[1005][4];

int main(){
    int n; cin >>n;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=3; ++j){
            cin >> cost[i][j];
        }
    }

    //base case
    d[1][0] = cost[1][0];
    d[1][1] = cost[1][1];
    d[1][2] = cost[1][2];

    for(int i=2; i<=n; ++i){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + cost[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + cost[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + cost[i][2];
    }   
    cout << min({d[n][0], d[n][1], d[n][2]});

}