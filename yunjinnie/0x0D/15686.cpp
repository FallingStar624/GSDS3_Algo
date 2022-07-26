// 도시 크기: N by N (<=50), 위치: (r, c)
// 거리: |r1-r2|+|c1-c2|
// 0: 빈 칸, 1: 집, 2: 치킨집
// 치킨거리: min(closest), 도시의 치킨거리: sum(치킨거리)
// 수익이 최대가 되는 치킨집 개수: M (<=13)-> 어떻게 골라야 도시의 치킨거리 최소?

// brute force, back tracking
// 거리 계산, dfs, main

#include <bits/stdc++.h>
/*#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
#include <climits>*/
using namespace std;

int N, M;
int board[51][51];
int ans = INT_MAX;
struct coord{
    // instead of using pair<int, int>
    int x;
    int y;
};
vector<coord> chicken;
vector<coord> home;
vector<coord> selected;
bool visited[13];


int dist(coord a, coord b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

void dfs(int idx, int cnt){
    // M개 고르기 및 최단 거리 구하기
    //if (cnt==chicken.size()) return;

    if (cnt==M){
        // calculate min of distance
        int tmp=0;
        for (int i=0; i<home.size(); i++){
            int d = INT_MAX;

            for (int j=0; j<M; j++){
                //int d = INT_MAX;
                d = min(d, dist(home[i], selected[j]));
            }
            tmp += d;
        }
        ans = min(tmp, ans);
    }

    // select M
    for(int i=idx; i<chicken.size(); i++){
        if (visited[i]==1) continue;
        else{
            visited[i]=1; // make it visited
            selected.push_back({chicken[i].x, chicken[i].y});
            dfs(i, cnt+1);

            visited[i]=0; // make it default
            //dfs(idx++, cnt);
            selected.pop_back();

        }
    // next_permutation?
    }

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin>>board[i][j];
            if (board[i][j]==1){
                home.push_back({i, j});
            }
            else if (board[i][j]==2){
                chicken.push_back({i, j});
            }
        }
    }

    dfs(0, 0);
    cout<<ans<<'\n';
    return 0;

}


//https://velog.io/@sj-lee33/%EB%B0%B1%EC%A4%80-15686-%EC%B9%98%ED%82%A8-%EB%B0%B0%EB%8B%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-c-%ED%92%80%EC%9D%B4
