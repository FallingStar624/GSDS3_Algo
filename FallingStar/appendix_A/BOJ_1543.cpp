#include <iostream>
#define endl '\n';
using namespace std;

string A, B;

int main() {
    getline(cin, A);
    getline(cin, B);
    int i=0, ans=0, N=A.size(), M=B.size(), val;
    string tmp;
    while (i<N-M+1) {
        tmp = A.substr(i, M);
        val = B.compare(tmp);
        if (val==0) {
            ans++;
            i += M;
        } else {
            i++;
        }
    }
    cout << ans;
    return 0;
}
