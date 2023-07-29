#include <map>
#include <set>
#include <iostream>
#include <string>
using namespace std;
int N, M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    map<int, int> m; multiset<pair<int, int>> ms;
    for(int i = 0; i < N; i++){
        int p, l; // p : 문제번호, l : 난이도
        cin >> p >> l;
        m[p] = l;
        ms.insert({l, p}); // 난이도 순 -> 문제번호 순으로 정렬
    }
    cin >> M;
    for (int i = 0; i < M; i++){
        string op;
        cin >> op;
        if (op == "add"){
            int p, l; // p : 문제번호, l : 난이도
            cin >> p >> l;
            m[p] = l;
            ms.insert({l, p});
        }
        if (op == "recommend"){
            int r; // 1: 어려운문제, -1 : 쉬운문제
            cin >> r;
            if (r == 1) {
                cout << prev(ms.end())->second << '\n';
                }
            if (r == -1){
                cout << ms.begin()->second << '\n';
                }
        }
        if (op == "solved"){
            int p, l; // p : 문제번호, l : 난이도
            cin >> p; // 입력이 뭔가 안되고 있으면 cin을 빼먹은 거일 수 있으니 확인필요.
            l = m[p];
            m.erase(p);
            ms.erase(ms.find({l, p}));
        }
    }
    return 0; 
}