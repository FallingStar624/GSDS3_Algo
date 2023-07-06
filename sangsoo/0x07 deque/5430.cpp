#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        string cmd;
        cin >> cmd;
        int n; cin >> n;
        deque <int> dq;
        string s; cin >> s;
        string snum = "";
        bool error = 0;  
        bool reversed = false; // add this to keep track of the deque's state
        for (int i =0; i < s.length(); i++){
            if (isdigit(s[i])){
                snum += s[i];
            }
            else{
                if(!snum.empty()){
                    dq.push_back(stoi(snum));
                    snum = "";
                }
            }
        }
        for (int i = 0; i < cmd.length(); i++){
            // R
            if (cmd[i] == 'R'){
                reversed = !reversed; // just flip the state instead of actually reversing the deque
            }
            // D
            if (cmd[i] == 'D'){
                if (dq.empty()) {
                    error = 1;
                }
                else{
                    // remove an element from the front or the back depending on the deque's state
                    if (reversed) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }
        if (error) cout << "error\n";
        else{
            if (reversed) reverse(dq.begin(), dq.end()); // actually rever the deque only if it's necessary
            cout << "[";
            if (!dq.empty()){ // empty를 확인 해줘야 dq.size()-1 에서 확인 가능...
                for (int i= 0; i< dq.size()-1; i++){
                    cout << dq[i] << ",";
                }
                cout << dq[dq.size()-1]; 
            }
            cout << "]\n";
        }
    }    
}