#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 
    cin >> N;

    queue<int> q;
    for (int i =0; i < N; i++){
    string str;
    cin >> str;

    if (str == "push"){
        int p;
        cin >> p;
        q.push(p);
    }
    else if (str == "front"){
        if (q.size() !=0){
        cout << q.front() << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    else if (str == "back"){
        if (q.size() !=0){
        cout << q.back() << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }        
    else if (str == "size"){
        cout << q.size() << '\n';
    }
    else if (str == "empty"){
        cout << q.empty() << '\n';
    }
    else if (str == "pop"){
        if (q.size() !=0){
            cout << q.front();
            q.pop();
            cout << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    }
}