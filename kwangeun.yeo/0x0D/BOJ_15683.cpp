#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int r;
    int c;
    int type;
    int dir;
} CCTV;
CCTV cctv[8];

int office[10][10];
int office_temp[10][10];
int cctv_cnt;
int min_area;
int R, C;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void Monitor(int sr, int sc, int dir);
int GetArea();
void Func(int cctv_idx);

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> office[r][c];
            if (office[r][c] >= 1 && office[r][c] <= 5) {
                cctv[cctv_cnt].r = r;
                cctv[cctv_cnt].c = c;
                cctv[cctv_cnt].type = office[r][c];
                cctv[cctv_cnt++].dir = 0;
            }
        }
    }

    min_area = R * C;
    Func(0);
    cout << min_area;

    return 0;
}

void Monitor(int sr, int sc, int dir) {
    int r = sr;
    int c = sc;
    for (;; r += dr[dir], c += dc[dir]) {
        if (r < 0 || c < 0 || r > R || c > C) break;
        if (office[r][c] == 6) break;
        office_temp[r][c] = -1;
    }
}

int GetArea() {
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            office_temp[r][c] = office[r][c];
        }
    }
    for (int i = 0; i < cctv_cnt; ++i) {
        int sr = cctv[i].r;
        int sc = cctv[i].c;
        Monitor(sr, sc, cctv[i].dir);
        if (cctv[i].type == 3 || cctv[i].type == 4 || cctv[i].type == 5) Monitor(sr, sc, (cctv[i].dir + 1) % 4);
        if (cctv[i].type == 2 || cctv[i].type == 5) Monitor(sr, sc, (cctv[i].dir + 2) % 4);
        if (cctv[i].type == 4 || cctv[i].type == 5) Monitor(sr, sc, (cctv[i].dir + 3) % 4);
    }

    int sum = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (office[r][c] == 0 && office_temp[r][c] != -1) sum++;
        }
    }
    return sum;
}

void Func(int cctv_idx) {
    if (cctv_idx >= cctv_cnt) {
        int area = GetArea();
        min_area = min(area, min_area);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        cctv[cctv_idx].dir = i;
        if (cctv[cctv_idx].type == 2 && i > 1) break;
        else if (cctv[cctv_idx].type == 5 && i > 0) break;
        Func(cctv_idx + 1);
    }
}