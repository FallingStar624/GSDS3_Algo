#include <iostream>
#include <algorithm>
#define ROW first
#define COL second
using namespace std;

int N, M;
int city[52][52];
pair<int,int> house[101];
pair<int, int> chi[15];
int chi_dist[101][15];
int selected_idx[15];
int house_cnt;
int chi_cnt;
int min_dist;

int GetChiDist();
void Func(int selected_cnt, int sidx);


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> city[r][c];
			if (city[r][c] == 1) house[house_cnt++] = { r, c };
			else if (city[r][c] == 2) chi[chi_cnt++] = { r, c };
		}
	}
	for (int i = 0; i < house_cnt; ++i) {
		for (int j = 0; j < chi_cnt; ++j) {
			chi_dist[i][j] = abs(house[i].ROW - chi[j].ROW) + abs(house[i].COL - chi[j].COL);
		}
	}

	min_dist = 100 * 100;
	Func(0, 0);
	cout << min_dist;

	return 0;
}


void Func(int selected_cnt, int sidx) {
	if (selected_cnt >= M) {
		int dist_sum = GetChiDist();
		min_dist = min(min_dist, dist_sum);
		return;
	}

	for (int i = sidx; i < chi_cnt - M + selected_cnt + 1; ++i) {
		selected_idx[selected_cnt] = i;
		Func(selected_cnt + 1, i + 1);
	}
}


int GetChiDist() {
	int dist_sum = 0;
	for (int i = 0; i < house_cnt; ++i) {
		int tmp_dist = 50 * 50;
		for (int j = 0; j < M; ++j) {
			int chi_idx = selected_idx[j];
			tmp_dist = min(tmp_dist, chi_dist[i][chi_idx]);
		}
		dist_sum += tmp_dist;
		if (dist_sum >= min_dist) return 100 * 100;
	}
	return dist_sum;
}