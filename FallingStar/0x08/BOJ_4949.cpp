#include <iostream>
#include <stack>
using namespace std;

stack<char> S;
string line;


int main() {
    while (true) {
        getline(cin, line, '.');
        if (line=="\n") break;
        for (char c: line) {
            if (c!=40 && c!=41 && c!=91 && c!=93) continue;
            if (S.empty()) {
                S.push(c);
            } else if (c==')' && S.top()=='(') {
                S.pop();
            } else if (c==']'&& S.top()=='[') {
                S.pop();
            } else if (c=='('|c==')'|c=='['|c==']') {
                S.push(c);
            } else {}
        }
        if (S.empty()) {
            cout << "yes" << endl;
        } else { cout << "no" << endl; }
        while(!S.empty()) S.pop();
    }
    return 0;
}

