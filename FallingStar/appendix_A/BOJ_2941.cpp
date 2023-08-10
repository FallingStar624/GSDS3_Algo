#include <iostream>
#define endl '\n';
using namespace std;

string A, tmp;
string arr[8] = {"c=", "c-", "z=", "d-",
                 "lj", "nj", "s=", "dz="};
int ans;

bool check(string tgt) {
    bool result = false;
    for (int i=0; i<7; i++) {
        int val = tgt.compare(arr[i]);
        if (!val) result = true;
    }
    return result;
}

int main() {
    getline(cin, A);
    int i = 0;
    while (i < A.size()) {
        ans++;
        tmp = A.substr(i, 2);
        if (check(tmp)) {
            i+=2;
        } else {
            tmp = A.substr(i, 3);
            if (tmp.compare(arr[7])==0) {
                i+=3;
            } else {
                i++;
            }
        }
    }
    cout << ans;
    return 0;
}
