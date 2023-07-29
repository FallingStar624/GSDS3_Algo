#include <iostream>
#include <set>
using namespace std;
int N, Q;
int d; // 도형이의 위치

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    set<int> s;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t; // cin 확인 잘해야..
        if(t) s.insert(i); // 1값만 저장
    }
    for(int i = 0; i < Q; i++){
        int op; // operation
        cin >> op;
        if(op == 1){
            int op1;
            cin >> op1;
            if(s.find(op1-1) != s.end()) s.erase(op1-1);
            else s.insert(op1-1);
        }
        else if(op == 2){ // if, else if, else로 안하고 if if else로 하면 틀린다. (왜냐면 1이되어도 3은 무조건 실행)
            int op2;
            cin >> op2;
            d = (d+op2) % N;
        }
        else{
            if(!s.size()) cout << -1 << '\n';
            else{
                if(s.lower_bound(d) != s.end()) cout << *s.lower_bound(d) -d << '\n';
                else cout << N - d + *s.begin() << '\n'; // N에서 빼줘야 함.
            }
        }
    }
}