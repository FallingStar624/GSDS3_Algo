#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    deque<int> dq;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        if(s == "push_back"){
            int j;
            cin >> j;
            dq.push_back(j);
        }
        if(s == "push_front"){
            int j;
            cin >> j;
            dq.push_front(j);
        }
        if(s == "front"){
            if(dq.size()) cout << dq.front() <<'\n';
            else cout<< -1 << '\n';
        }
        if(s == "back"){
            if(dq.size()) cout << dq.back()<<'\n';
            else cout<< -1<< '\n';
        }
        if(s == "size"){
            cout << dq.size()<<'\n';
        }
        if(s == "empty"){
            cout << dq.empty() << '\n';
        }
        if(s == "pop_front"){
            if(dq.size()) {
                cout << dq.front()<< '\n';
                dq.pop_front();
            }
            else cout << -1<< '\n';
        }
        if(s == "pop_back"){
            if(dq.size()){
                cout << dq.back()<< '\n';
                dq.pop_back();
            }
            else cout<< -1<< '\n';
        }
    }
}

