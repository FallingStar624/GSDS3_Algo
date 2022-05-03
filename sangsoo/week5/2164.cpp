#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    queue<int> q;
    for (int i = 1; i < N+1; i++){
        q.push(i);
    }
    while (q.size() > 1){
        q.pop();
        q.push(q.front());
        if (q.size() > 1){
        q.pop();
        }
    }
    cout << q.front();

    return 0;
}