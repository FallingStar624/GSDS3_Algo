#include <queue>
#include <iostream>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
            cin >> x;
            q.push(x);
    }
   for (int i=1;i<N; i++) {
       for (int j=0; j<N; j++) {
           cin >> x;
           q.push(x);
           q.pop();
       }
   }
    cout << q.top() << endl;
    return 0;
}

