#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l, c;
vector<char> inputs;
vector<string> answers;

bool valid_check(string target) {
    int vowel;
    for (char c: target) {
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') vowel++;
    }
    if (vowel<1) return false;
    if (l-vowel<2) return false;
    return true;
}

void back_track(string cur) {
    if (cur.length()==l) {
        if (valid_check(cur)) {
            answers.push_back(cur);
            return;
        }
    }
    for (auto i=inputs.begin(); i<inputs.end(); i++) {
        if (cur.back()<*i) back_track(cur+*i);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for (int i=0; i<c; i++) {
        char tmp;
        cin >> tmp;
        inputs.push_back(tmp);
    }
    sort(inputs.begin(), inputs.end());
    back_track("");
    for (string ans: answers) {
        cout << ans;
        if (ans!=answers.back()) cout << "\n";
    }
    return 0;
}
