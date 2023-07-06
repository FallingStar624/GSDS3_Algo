// Time limit exceeded 
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
                deque<int> tmp;
                while (!(dq.empty())){
                    tmp.push_back(dq.back());
                    dq.pop_back();
                }
                dq = tmp;
            }
            // D
            if (cmd[i] == 'D'){
                if (dq.empty()) {
                    error = 1;
                }
                else{
                    dq.pop_front();
                }
            }
        }
        if (error) cout << "error\n";
        else{
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