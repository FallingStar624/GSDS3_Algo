#include <iostream>
#include <vector>

using namespace std;

vector<string> letters = {
    "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    string w;
    cin >> w;

    for(auto letter : letters) {
        while(1) {
            int pos = w.find(letter);
            if(pos == string::npos) break;
            w.replace(pos, letter.size(), "*");
        }
    }
    cout << w.size();

    return 0;
}