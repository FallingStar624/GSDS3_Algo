#include <iostream>
#include <string>
using namespace std;

string A, tmp;
int N;

int main() {
    cin >> N;
    cin >> A;
    string head, tail, in_head, in_tail;
    int ast_pos = A.find('*');
    head = A.substr(0, ast_pos);
    tail = A.substr(ast_pos+1, A.length());
    for (int i=0; i<N; i++) {
        cin >> tmp;
        if (tmp.length() < head.length() + tail.length()) {
            cout << "NE" << endl;
            continue;
        }
        in_head = tmp.substr(0, ast_pos);
        in_tail = tmp.substr(tmp.length()-tail.length(), tmp.length());
        if (head==in_head && tail==in_tail) { cout << "DA" << endl; }
        else { cout << "NE" << endl; }
    }
    return 0;
}
