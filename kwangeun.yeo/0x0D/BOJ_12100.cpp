#include <iostream>
#include <algorithm>

using namespace std;

int board[21][21];
int N;
int max_block;

void MoveUp();
void MoveDown();
void MoveLeft();
void MoveRight();
void CopyBoard(int src[21][21], int dst[21][21]);
void Func(int move);


int main() {
	cin >> N;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> board[r][c];
		}
	}

	max_block = 0;
	Func(0);
	cout << max_block;

	return 0;
}

void Func(int move) {
	if (move >= 5) {
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				max_block = max(board[r][c], max_block);
			}
		}
		return;
	}

	int temp_board[21][21];
	CopyBoard(board, temp_board);
	MoveUp();
	Func(move + 1);
	CopyBoard(temp_board, board);
	MoveDown();
	Func(move + 1);
	CopyBoard(temp_board, board);
	MoveLeft();
	Func(move + 1);
	CopyBoard(temp_board, board);
	MoveRight();
	Func(move + 1);
	CopyBoard(temp_board, board);
}


void CopyBoard(int src[21][21], int dst[21][21]) {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			dst[r][c] = src[r][c];
		}
	}
}


void MoveUp() {
	for (int c = 0; c < N; ++c) {
		int cnt = 0;
		for (int r = 0; r < N; ++r) {
			if (board[r][c] != 0) board[cnt++][c] = board[r][c];
		}
		for (int r = cnt; r < N; ++r) {
			board[r][c] = 0;
		}

		for (int r = 0; r < N - 1; ++r) {
			if (board[r][c] == board[r + 1][c]) {
				board[r][c] *= 2;
				board[r + 1][c] = 0;
			}
		}

		cnt = 0;
		for (int r = 0; r < N; ++r) {
			if (board[r][c] != 0) board[cnt++][c] = board[r][c];
		}
		for (int r = cnt; r < N; ++r) {
			board[r][c] = 0;
		}
	}
}


void MoveLeft() {
	for (int r = 0; r < N; ++r) {
		int cnt = 0;
		for (int c = 0; c < N; ++c) {
			if (board[r][c] != 0) board[r][cnt++] = board[r][c];
		}
		for (int c = cnt; c < N; ++c) {
			board[r][c] = 0;
		}

		for (int c = 0; c < N - 1; ++c) {
			if (board[r][c] == board[r][c + 1]) {
				board[r][c] *= 2;
				board[r][c + 1] = 0;
			}
		}

		cnt = 0;
		for (int c = 0; c < N; ++c) {
			if (board[r][c] != 0) board[r][cnt++] = board[r][c];
		}
		for (int c = cnt; c < N; ++c) {
			board[r][c] = 0;
		}
	}
}


void MoveDown() {
	for (int c = 0; c < N; ++c) {
		int cnt = 0;
		for (int r = N - 1; r >= 0; --r) {
			if (board[r][c] != 0) board[N - 1 - cnt++][c] = board[r][c];
		}
		for (int r = N - 1 - cnt; r >= 0; --r) {
			board[r][c] = 0;
		}

		for (int r = N - 1; r > 0; --r) {
			if (board[r][c] == board[r - 1][c]) {
				board[r][c] *= 2;
				board[r - 1][c] = 0;
			}
		}
		
		cnt = 0;
		for (int r = N - 1; r >= 0; --r) {
			if (board[r][c] != 0) board[N - 1 - cnt++][c] = board[r][c];
		}
		for (int r = N - 1 - cnt; r >= 0; --r) {
			board[r][c] = 0;
		}
	}
}


void MoveRight() {
	for (int r = 0; r < N; ++r) {
		int cnt = 0;
		for (int c = N - 1; c >= 0; --c) {
			if (board[r][c] != 0) board[r][N - 1 - cnt++] = board[r][c];
		}
		for (int c = N - 1 - cnt; c >= 0; --c) {
			board[r][c] = 0;
		}

		for (int c = N - 1; c > 0; --c) {
			if (board[r][c] == board[r][c - 1]) {
				board[r][c] *= 2;
				board[r][c - 1] = 0;
			}
		}

		cnt = 0;
		for (int c = N - 1; c >= 0; --c) {
			if (board[r][c] != 0) board[r][N - 1 - cnt++] = board[r][c];
		}
		for (int c = N - 1 - cnt; c >= 0; --c) {
			board[r][c] = 0;
		}
	}
}