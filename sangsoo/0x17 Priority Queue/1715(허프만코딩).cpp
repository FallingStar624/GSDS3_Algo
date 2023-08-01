#include <iostream>
#include <queue>
using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--){
        int x;
        cin >> x;
        pq.push(x);
    }
    int sum = 0;
    while(pq.size()>1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += a + b;
        pq.push(a+b); // 합쳐진 카드를 넣어줘야함
    }
    cout << sum;
}