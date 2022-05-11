#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

deque<string> deq;
string str, tmp, num;
int t, n, i;
int R = 1;
bool err = false;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    for (i=0; i<t; i++) {
        cin >> str >> n >> num;
        num.erase(num.begin());
        num.erase(num.end()-1);
        stringstream nums(num);
        // 번호들 deque에 입력
        while (getline(nums, tmp, ',')) {
            deq.push_back(tmp);
        }
        // 명령어 실행
        for (auto a : str) {
            if (a=='R') { // REVERSE
                R *= (-1);
            } else {
                if (deq.empty()) err=true;
                else {
                    if (R>0){
                        deq.pop_front();
                    } else {
                        deq.pop_back();
                    }
                }
            }
        }
        if (err) {
            cout << "error" << '\n';
        }
        else {
            if (R<0) {
                string result = "]";
                for (auto s: deq) {
                    result = "," + s + result;
                }
                if (result.length()>1) {
                    result = result.substr(1, result.length()-1);
                }
                result = "[" + result;
                cout << result << '\n';
            } else {
                string result = "[";
                for (auto s: deq) {
                    result += s;
                    result += ",";
                }
                if (result.length()>1) {
                    result = result.substr(0, result.length()-1);
                }
                result += "]";
                cout << result << '\n';
            }
        }
        deq.clear();
        err = false;
        R = 1;
    }
    return 0;
}

