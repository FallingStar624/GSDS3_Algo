#include <iostream>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;

int n;
int dx = {0, 0, -1, 1}; // top bottom left right
int dy = {-1, 1, 0, 0};

int ans = INT_MIN;
struct pannel {
    int val = 0;
    int x, y;
    bool isused = false;
};
vector<pannel> pannels;

int board[21][21];
int board_temp[21][21];
bool isused[21][21];

void PrintBoard();
bool IsOutbound(int a, int b);
void Func(int move_idx);
void Move(int dir);
int FindMaxPannel();
void Init();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0) {
                pannel pan;
                pan.val = board[i][j];
                pan.x = i;
                pan.y = j;
                pannels.push_back(pan);
            }
        }
    }
    Func(0);
    return 0;
}

void Func(int move_idx) {

    if(move_idx == 5) {
        int max_pan = FindMaxPannel();
        ans = max(ans, max_pan);
        return;
    }

    for(int dir = 0; dir < 4; dir++) {
        Move(dir);
        Func(move_idx + 1);
        Init();
    }

}

void Init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board_temp[i][j] = board[i][j];
        }
    }
}

void Move(int dir) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            
            , ny = i, j;

            int beforeval = brd[nx][ny].val;
            if(brd[nx][ny].val == 0)
                continue;
            
            
            nx = nx + dx[dir];
            ny = ny + dy[dir];

            while(isOutbound(nx, ny)) {

                if(!brd[nx][ny].isused && brd[nx][ny] == beforeval) {
                    brd[nx][ny].isused = true; 
                    brd[nx][ny].val += beforeval;
                    
                }
                beforeval = brd[nx][ny].val;
            }

        }
    }

}


void PrintBoard() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j].val << " ";
        }
        cout << "\n";
    }
}

bool IsOutbound(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= n;
}

int FindMaxPannel() {
    int maxPan = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            maxPan = max(maxPan, brd[i][j].val);
        }
    }
    return maxPan;
}
