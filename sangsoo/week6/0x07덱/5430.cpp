// TIME OVER
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
void makenumber(string &arr, deque<int> &dq){
    string temp;
    for (int i = 0; i < arr.length(); i++){
        if(arr[i] == '[') continue;
        if('0' <= arr[i] && arr[i] <= '9') temp += arr[i];
        if(arr[i] == ',' || arr[i] == ']'){
            if(!temp.empty()){
                dq.push_back(stoi(temp));
                temp.clear();
            }
        }
    }
}

void makeoutput(deque<int> &dq){
    if(dq.size()) cout << '[';
    for(int i = 0; i < dq.size(); i++){
        if(i != dq.size()-1) cout << dq[i] << ',';
        else cout << dq[i] << ']'<< '\n';
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int T, n;
    string p, arr;
    deque<int> mdq;
    cin >> T;
    while(T--){
        cin >> p >> n >> arr;
        makenumber(arr, mdq);
        for(int i = 0; i < p.size(); i++){
            if(p[i] =='R') reverse(mdq.begin(), mdq.end());
            else if (p[i] =='D') {
                if(mdq.size()) mdq.pop_front();
                else cout << "error" << '\n';
            }
        }
        makeoutput(mdq);
        mdq.clear();
    }
}