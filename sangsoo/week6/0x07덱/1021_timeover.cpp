#include <iostream>
#include <deque>
using namespace std;
int N, M;
int ans = 0;
deque<int> dq;

void func2(){
    dq.push_back(dq.front());
    dq.pop_front();
    ans += 1;
}

void func3(){
    dq.push_front(dq.back());
    dq.pop_back();
    ans += 1;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {  // make deque dq
        dq.push_back(i);
    }

    for (int i = 0; i < M; i++) { // 
        int j;
        cin >> j;
        if(dq[0] == j){
            dq.pop_front();
        }   
        else{
            for(int k = 0; k < N; k++) { // find j in dq
                if(dq[k] ==j){
                    if(k < dq.size()/2){
                        for(int a = 0; a < k; a++){func2();}
                        dq.pop_front();
                    }
                    else{
                        for(int a = 0; a < dq.size()-k; a++){func3();}
                        dq.pop_front();
                    }
                }
            }

        }
    }
    cout << ans;
}