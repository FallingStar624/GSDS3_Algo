#include <iostream>
#include <deque>
using namespace std;
int N, M, p;
int ans = 0;
deque<int> dq;
int find_num[51];
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
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        find_num[i] = n;
    } 

    for (int i = 0; i < M; i++) {
        if(dq.size() == 1) continue; //  
        for(int j = 0; j < N; j++) {
            if(find_num[i] == dq.at(j)){
                p = j; // save index
                break;
            }
        }
        if(p <= dq.size()/2){ // 2nd operation
            for(int j = 0; j< p; j++){func2();}
            dq.pop_front();
        }
        else{ // 3rd operation
            for(int j = 0; j <dq.size()-p; j++){func3();}
            dq.pop_front();
        }
    }
    cout << ans;
}