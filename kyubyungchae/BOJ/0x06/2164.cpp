#include <iostream>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    queue<int> q;
    for(int i = 1; i <= N; ++i) 
        q.push(i);

    while(q.size() != 1) {  
        q.pop();
        int card = q.front();
        q.pop();        
        q.push(card);
    }

    cout << q.front();
    return 0;
}