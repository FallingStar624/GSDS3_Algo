#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

void parse(string& tmp, deque<int>& d){
  int cur = 0;
  for(int i = 1; i+1 < tmp.size(); i++)
  {
    if(tmp[i] == ','){
      d.push_back(cur);
      cur = 0;
    }
    else{
      cur = 10 * cur + (tmp[i] - '0');
    }
  }
  if(cur != 0)
    d.push_back(cur);
}

string getMessage(deque<int>& dq, bool isRev, bool isError) {
    if(isError)
        return "error";
    
    string msg = "[";
    if(isRev) {
        for(int i = dq.size() - 1; i >= 0; i--) {
            msg += to_string(dq[i]);
            if(i > 0)
                msg += ",";
        }
    } else {
        for(int i = 0; i < dq.size(); i++) {
            msg += to_string(dq[i]);
            if(i < dq.size() - 1)
                msg += ",";
        }
    }
    msg += "]";
    return msg;
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        deque<int> dq;

        string oper;
        cin >> oper;
        
        int n;
        cin >> n;

        string strArr;
        cin >> strArr;
        parse(strArr, dq);

        int isRev = 0;
        bool isError = false;
        for(char c : oper) {
            if(c == 'R') {
                isRev = 1 - isRev;
            } else {
                if(dq.empty()) {
                    isError = true;
                    break;
                }

                if(isRev) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }
        cout << getMessage(dq, isRev, isError) << '\n';
    }

    return 0;
}