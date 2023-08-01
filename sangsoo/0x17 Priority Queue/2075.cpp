/*
바킹독 풀이를 보니 최소힙으로두고 N개만 남기고 계속 없애면 된다. 반대로생각한거.
*/
#include <iostream>
#include <queue>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;   
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int t;
            cin >> t;
            pq.push(t);
            if (n < pq.size()) pq.pop();
        }
    }
    cout << pq.top();
}