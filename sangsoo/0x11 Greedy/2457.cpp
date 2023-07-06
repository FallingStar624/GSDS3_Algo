#include <bits/stdc++.h>
using namespace std;
 
typedef struct _flower{
    int s, e; // 꽃이 피는 일, 꽃이 지는 일
}flower;
 
int mtod(int month, int date){  // 월, 일을 입력 받아 일수로 변경하는 함수
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return accumulate(day, day + month, 0) + date;
}
 
bool cmp1(flower f1, flower f2){    // 꽃이 빨리 피는 순으로 정렬
    if(f1.s == f2.s) return f1.e < f2.e;
    return f1.s < f2.s; 
} 
bool cmp2(flower f1, flower f2){return f1.e > f2.e;} // 꽃이 늦게 지는 순으로 정렬
 
flower flowers[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        flowers[i] = {mtod(s1, s2), mtod(e1, e2)};    // 각 꽃의 정보 입력 받음
    } 
 
    sort(flowers, flowers + n, cmp2);   // 꽃이 늦게 지는 순으로 정렬
    if(mtod(12, 1) > flowers[0].e) {cout << 0 << "\n"; return 0;}    // 11월 30일 이후에 지는 꽃이 없으면 0 출력
    sort(flowers, flowers + n, cmp1);
    if(mtod(3, 1) < flowers[0].s) {cout << 0 << "\n"; return 0;}    // 3월 2일 이전에 피는 꽃이 없으면 0 출력
 
    int cur = 0;    // 3월 1일 이전에 피는 꽃 중 가장 늦게 피는 꽃의 idx
    for(int i = 1; i < n; i++){
        flower f = flowers[i];
        if(f.s <= mtod(3, 1))
            if(f.e > flowers[cur].e)
                cur = i;
    }
 
    int ans = 1;    // 선택한 꽃들의 최소 개수
    // cur은 현재 피어있는 꽃을 의미
    while(true){
        if(flowers[cur].e > mtod(11, 30)) break;    // 현재 피어있는 꽃이 11월 30일 이후에 지는 경우 반복을 종료
 
        flower l = {1, 1}; // 가장 늦게 지는 꽃
        int l_idx = -1; // 가장 늦게 지는 꽃의 인덱스
        for(int i = cur + 1; i < n; i++){   
            flower f = flowers[i];
            if(f.s <= flowers[cur].e){    // 현재 피어있는 꽃이 지기 전에 피고,     
                if(f.e > l.e){  // 그 중 가장 늦게 지는 꽃을 찾음
                    l = f;
                    l_idx = i;
                }        
            }
        }
 
        cur = l_idx;    // 현재 피어있는 꽃의 인덱스 변경
 
        if(l.s == 1){    // 현재 피어있는 꽃이 지기 전에 피는 꽃이 없는 경우
            cout << 0 << "\n"; return 0;
        }else{ans++;}   // 선택한 꽃의 개수 증가
    }
 
    cout << ans;
}