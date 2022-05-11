//39%...
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct bracket {
    char sym;
    int value;
    bracket(char a, int b=-1) : sym(a), value(b) {}
};

int tmp=-1, answer=0;
string str;
deque<bracket> dq1;
deque<bracket> dq2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    for (char c: str) {
        dq1.emplace_back(bracket(c));
    }
    while (!dq1.empty()) {
        if (dq1.size()==1 && dq1.front().sym == '#') {
            answer = dq1.front().value;
            break;
        }
        for (auto b : dq1) {
            if (b.sym=='(' | b.sym=='[') {
                if (tmp>0) {
                    dq2.emplace_back(bracket('#', tmp));
                    dq2.emplace_back(bracket(b.sym));
                    tmp=-1;
                } else {
                    dq2.emplace_back(bracket(b.sym));
                }
            } else if (b.sym=='#') {
                if (tmp > 0) {
                    tmp += b.value;
                } else {
                    tmp = b.value;
                }
            } else if (!dq2.empty() && b.sym==')' && dq2.back().sym == '(') {
                dq2.pop_back();
                if (tmp>0) {
                    dq2.emplace_back(bracket('#', 2*tmp));
                    tmp = -1;
                } else {
                    dq2.emplace_back(bracket('#', 2));
                }
            } else if (!dq2.empty() && b.sym==']' && dq2.back().sym == '[') {
                dq2.pop_back();
                if (tmp>0) {
                    dq2.emplace_back(bracket('#', 3*tmp));
                    tmp = -1;
                } else {
                    dq2.emplace_back(bracket('#', 3));
                }
            } else {
                dq2.emplace_back(bracket(b.sym));
            }
        }
        if (tmp>0) dq2.emplace_back(bracket('#', tmp));
        tmp = -1;
        if (dq1.size() == dq2.size()) {
            answer=0;
            break;
        }
        dq1.clear();
        swap(dq1, dq2);

    }
    cout << answer;
    return 0;
}

