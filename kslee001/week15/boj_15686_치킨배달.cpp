// 15686 치킨 배달 simulation
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define Y first
#define X second
using namespace std;

int n, m;
int num_store;
int num_cases;
int origin[50][50];
int clone[50][50];
vector<int> selected[2000];       // 모든 경우의 조합을 저장하기 위한 vector
                                  /* e.g.   selected[0] = {0,1,2,3}
                                            selected[1] = {0,1,2,4}
                                            selected[2] = {0,1,3,4} 
                                            ...
                                  */      
vector<pair<int,int>> stores;     // store 위치 저장하는 vector
vector<pair<int,int>> houses;     // house 위치 저장하는 vector
vector<pair<int,int>> clone_mem;  // clone에서 만들어지는 store 위치를 저장하는 vector (reset 빠르게 하려고)

int get_combination(int,int);
void input(){
    cin >>n>>m;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >>origin[i][j];
            clone[i][j] = origin[i][j];
            if(origin[i][j] == 1) {
                houses.push_back({i,j});
            }
            if(origin[i][j] == 2) {
                stores.push_back({i,j});
                ++num_store;
            }
        }
    }
    num_cases = get_combination(num_store,m);
}

// 모든 경우의 조합을 찾아서 selected vector에 저장하는 함수 
int get_combination(int num_store, int m){
    vector<int> s; 
    vector<int> temp; 
    // 0 ~ num_store-1 
    for(int i=0; i<num_store; ++i) s.push_back(i);
    // generate mask
    for(int i=0; i<m; ++i)         temp.push_back(1);
    for(int i=m; i<num_store; ++i) temp.push_back(0);
    int num_case = -1;
    do{
        ++num_case;
        for(int i=0; i<s.size(); ++i){
            if(temp[i]) selected[num_case].push_back(s[i]);
        }
    } while(prev_permutation(temp.begin(), temp.end()));
    return num_case+1;
}

// 매번의 case가 시작되기 전, 이전 case에서 썼던 store들을 clone 맵에서 모두 지우는 함수
void reset_clone(){
    for(int i=0; i<clone_mem.size(); ++i){
        pair<int,int> cur = clone_mem[i];
        clone[cur.Y][cur.X] = 0;
    }
}

// 매번의 case에 해당되는 store들을 불러와서 clone에 작성하는 함수
void load_case(int c_idx){
    reset_clone();
    for(int i=0; i<m; ++i){
        int s_idx = selected[c_idx][i];
        pair<int,int> cur = stores[s_idx];
        clone_mem.push_back(cur);
        clone[cur.Y][cur.X] = 2;
    }
}

// 특정 case의 특정 house의 최소 치킨 거리를 구하기 위한 함수
int get_dist_aux(int c_idx, int h_idx){
    int cur_MIN = INT_MAX; // cur_MIN : 개별 집의 "최소" 치킨거리
    pair<int,int> cur_house = houses[h_idx];
    for(int s_idx = 0; s_idx<m; ++s_idx){
        int cur_store_idx = selected[c_idx][s_idx];
        pair<int,int> cur_store = stores[cur_store_idx];
        // cur_dist : 개별 집 vs 개별 store의 치킨거리
        int cur_dist = abs(cur_house.Y - cur_store.Y) + abs(cur_house.X - cur_store.X);
        // cur_MIN에 지금까지 나온 dist 중 최솟값을 저장
        if(cur_MIN > cur_dist) cur_MIN = cur_dist; 
    }
    return cur_MIN;
}

// 특정 case의 모든 집의 최소 치킨거리의 합 구하는 함수
int get_dist(int c_idx){
    int dist_sum = 0;
    for(int h_idx = 0; h_idx<houses.size(); ++h_idx){
        int cur_house_dist = get_dist_aux(c_idx, h_idx);
        dist_sum += cur_house_dist;
    }
    return dist_sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int res = INT_MAX;
    input();
    for(int c_idx=0; c_idx<num_cases; ++c_idx){
        load_case(c_idx);
        int cur = get_dist(c_idx);
        if(res > cur) res = cur;
    }

    cout << res;
}