#include <iostream>
#include <vector>
using namespace std;
int k=1;
string end_point;
vector<int> s;

bool check_sum(string cur_str) {
    int tmp;
    for (char c: cur_str) {
        tmp += c - 48;
    }
    if (tmp ==6) {
        return true;
    }
    return false;
}

void backtrack(string cur) {
    if (cur.length()==k) {
        if (check_sum(cur)) {
            auto idx = s.begin();
            for (char c: cur) {
                if (c=='1') {
                    cout << *idx << " ";
                }
                idx++;
            }
            if (cur != end_point) { cout << "\n"; };
            return;
        }
        return;
    }
    else {
        backtrack(cur+"1");
        backtrack(cur+"0");
    }
}

void lotto(int k) {
    if (k!=0) {
        for (int i=0; i<k ;++i) {
            int tmp;
            cin >> tmp;
            s.push_back(tmp);
        }
        end_point = "";
        for (int i=0; i<k-6; ++i) {
            end_point += '0';
        }
        for (int i=0; i<6; ++i) {
            end_point += '1';
        }
        backtrack("");
        while (!s.empty()) {
            s.pop_back();
        }
    }
};

int main() {
    cin >> k;
    while (k>0) {
        lotto(k);
        cin >> k;
        if (k!=0) {
            cout << "\n";
            cout << "\n";
        }
    }
    return 0;
}
