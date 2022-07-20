#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>

using namespace std;

int n, m;
int board[10][10];
vector<pair<int,int>> cctv;
int min_stk = INT_MAX;

int countZero() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

void go_top(int x, int y) {
    for(int i = x; i >= 0; i--) {
        if(board[i][y] == 6) {
            break;
        }
        if(board[i][y] != 0) {
            continue;
        }
        if(board[i][y] == 0) {
            board[i][y] = -1;
        } 
    }         
}

void go_bottom(int x, int y) {
    for(int i = x; i < n; i++) {
        if(board[i][y] == 6) {
            break;
        }
        if(board[i][y] != 0) {
            continue;
        }
        if(board[i][y] == 0) {
            board[i][y] = -1;
        }
    }      
}

void go_right(int x, int y) {
    for(int j = y; j < m; j++) {
        if(board[x][j] == 6) {
            break;
        }
        if(board[x][j] != 0) {
            continue;
        }
        if(board[x][j] == 0) {
            board[x][j] = -1;
        }
    }    
}

void go_left(int x, int y) {
    for(int j = y; j >= 0; j--) {
        if(board[x][j] == 6) {
            break;
        }
        if(board[x][j] != 0) {
            continue;
        }
        if(board[x][j] == 0) {
            board[x][j] = -1;
        } 
    }     
}

void do_cctv_5(int x, int y) {
    go_left(x, y);
    go_top(x, y);
    go_right(x, y);
    go_bottom(x, y);
}


void do_cctv_4(int x, int y, int dir) {

    switch (dir % 4)
    {
    case 0 : // "right"
        go_left(x, y);
        go_top(x, y);
        go_right(x, y);
        break;
    case 1 : // "bottom":
        go_top(x, y);
        go_right(x, y);
        go_bottom(x, y);
        break;
    case 2 : // "left":
        go_right(x, y);
        go_bottom(x, y);
        go_left(x, y);
        break;
    case 3 : // "top":
        go_bottom(x, y);
        go_left(x, y);
        go_top(x, y);
        break;
    default:
        break;
    }
}

void do_cctv_3(int x, int y, int dir) {
    switch (dir % 4)
    {
    case 0 : // "right":
        go_top(x, y);
        go_right(x, y);
        break;
    case 1 :// "bottom":
        go_right(x, y);
        go_bottom(x, y);
        break;
    case 2 : //"left":
        go_bottom(x, y);
        go_left(x, y);
        break;
    case 3: // "top":
        go_left(x, y);
        go_top(x, y);
    default:
        break;
    }

}


void do_cctv_2(int x, int y, int dir) {
    switch (dir % 2)
    {
    case 0 : //"horizon":
        go_left(x, y);
        go_right(x, y);    
        break;
    case 1 : //"vertical":
        go_top(x, y);
        go_bottom(x, y);
        break;
    default:
        break;
    }
}


void do_cctv_1(int x, int y, int dir) {
    switch (dir % 4)
    {
    case 0 : //"right":
        go_right(x, y);
        break;
    case 1 : //"bottom":
        go_bottom(x, y);
        break;
    case 2 : //"left":
        go_left(x, y);
        break;   
    case 3 : //"top":
        go_top(x, y);
        break; 
    default:
        break;
    }
}


int do_cctv(int x, int y, int k, int dir) {

    switch (k)
    {
    case 1:
        do_cctv_1(x, y, dir);
        break;
    case 2:
        do_cctv_2(x, y, dir);
        break;   
    case 3:
        do_cctv_3(x, y, dir);
        break;                
    case 4:
        do_cctv_4(x, y, dir);
        break;   
    case 5:
        do_cctv_5(x, y);
        break;           
    default:
        break;
    }

}



void reset_board() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] < 0)
                board[i][j] = 0;
        }
    }
}

int ans = INT_MAX;

void func(int s, int arr[10][10], vector<pair<int,int>> cctv) {

    if(s > 5) {
        ans = min(ans, countZero(arr));
        return;
    }

    int new_board[10][10];
    memcpy(new_board, arr, sizeof(int) * 10 * 10); 

    for(int dir = 0; dir < 4; dir++) {
        
        do_cctv(dir, new_board);
        func(s+1, new_board, cctv);
    }    
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6)
                cctv.push_back({i,j});
        }
    }

    
    int dir = 0;

    func(x, y, 1, board);

    for(int i = 0; i < cctv.size(); i++) {
        int x, y;
        tie(x, y) = cctv[i];
        
    } 
    
    cout << ans << '\n';

    return 0;
}