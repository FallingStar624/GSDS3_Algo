// 메모리초과
#include <iostream>
#include <queue>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, less<int>> pq;   // priority_queue<int, vector<int>, greater<int>>로 선언시 최소 힙
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int t;
            cin >> t;
            pq.push(t);
        }
    }
    n -= 1;
    while(n--){
        pq.pop();
    }
    cout << pq.top() ;

}