#include <iostream>
#include <cstring>

using namespace std;

int D[1002][1002];
char sen1[1002];
char sen2[1002];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> sen1 >> sen2;
    for (int i = 1; i <= strlen(sen1); ++i) {
        for (int j = 1; j <= strlen(sen2); ++j) {
            if (sen1[i - 1] == sen2[j - 1]) D[i][j] = D[i - 1][j - 1] + 1;
            else D[i][j] = max(D[i - 1][j], D[i][j - 1]);
        }
    }
    cout << D[strlen(sen1)][strlen(sen2)];

    return 0;
}