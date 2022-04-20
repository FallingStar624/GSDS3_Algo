#include <bits/stdc++.h>
using namespace std;

int N, K, len = 0;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    queue <int> q;
    for (int i=0;i<N;i++)
    {
        q.push(i+1);
    }
    cout<<"<";
    while (N>0)
    {
        for (int i=0;i<K-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        if (N>1)
        {cout<<", ";}
        q.pop();
        N--;
    }
    cout<<">";


}