#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cnt;
bool mask[25];
string board[5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++)
        cin >> board[i];
    
    fill(mask + 7, mask + 25, true);
    

    return 0;
}