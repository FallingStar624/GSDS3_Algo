// 정답 확인 했음
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int road[100002];

// int road[100002];
int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(road, road+100002, -1); // road 배열 -1로 초기화
    cin >> n >> k;
    queue <int> q;
    road[n] = 0;
    q.push(n);
    //cout << q.front() << endl;
    //cout << road[k] << endl;
    //cout << road[1] << ' '<< road[2] << endl;
    while (road[k] == -1) {
        int cur = q.front(); q.pop();
        //cout << cur << endl;
        for (int nxt : {cur-1, cur+1, 2*cur}){
            if(nxt < 0 || nxt > 100000) continue; // 범위를 벗어나면 지나감
            if(road[nxt] != -1  ) continue; // 방문하지 않은 곳(-1인 곳만)만 진행 <=> -1이 아니면 방문했으므로 지나감
            road[nxt] = road[cur]+1;
            q.push(nxt);
        }
    } 
    cout << road[k];
}