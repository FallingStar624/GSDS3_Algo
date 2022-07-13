#include <iostream>
using namespace std;

typedef struct {
    int height;
    int width;
    int shape[10][10];
} STICKER;
int R, C, K;
int laptop[40][40];
int rotated[10][10];
STICKER sticker[100];

void Swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }
void Rotate(int s_idx);
bool Search(int s_idx);
bool Stick(int sr, int sc, int s_idx);

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C >> K;
    for (int i = 0; i < K; ++i) {
        cin >> sticker[i].height >> sticker[i].width;
        for (int r = 0; r < sticker[i].height; ++r) {
            for (int c = 0; c < sticker[i].width; ++c) {
                cin >> sticker[i].shape[r][c];
            }
        }
    }

    for (int i = 0; i < K; ++i) {
        for (int rotate = 0; rotate < 4; ++rotate) {
            if (Search(i)) break;
            Rotate(i);
        }
    }

    int sum = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            sum += laptop[r][c];
        }
    }
    cout << sum;
    return 0;
}

bool Stick(int sr, int sc, int s_idx) {
    for (int i = 0; i < sticker[s_idx].height; ++i) {
        for (int j = 0; j < sticker[s_idx].width; ++j) {
            if (laptop[sr + i][sc + j] == 1 && sticker[s_idx].shape[i][j] == 1) return false;
        }
    }
    return true;
}

bool Search(int s_idx) {
    for (int r = 0; r < R - sticker[s_idx].height + 1; ++r) {
        for (int c = 0; c < C - sticker[s_idx].width + 1; ++c) {
            if (Stick(r, c, s_idx)) {
                for (int i = 0; i < sticker[s_idx].height; ++i) {
                    for (int j = 0; j < sticker[s_idx].width; ++j) {
                        if (sticker[s_idx].shape[i][j] == 1) laptop[r + i][c + j] = 1;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void Rotate(int s_idx) {
    Swap(sticker[s_idx].height, sticker[s_idx].width);
    for (int r = 0; r < sticker[s_idx].height; ++r) {
        for (int c = 0; c < sticker[s_idx].width; ++c) {
            rotated[r][c] = sticker[s_idx].shape[sticker[s_idx].width - 1 - c][r];
        }
    }
    for (int r = 0; r < sticker[s_idx].height; ++r) {
        for (int c = 0; c < sticker[s_idx].width; ++c) {
            sticker[s_idx].shape[r][c] = rotated[r][c];
        }
    }
}