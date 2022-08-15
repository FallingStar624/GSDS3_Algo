#include <iostream>
#include <algorithm>
using namespace std;
#define R (0)
#define G (1)
#define B (2)

int D[1002][3];
int cost[1002][3];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < 3; ++i) {
		cin >> cost[1][i];
		D[1][i] = cost[1][i];
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> cost[i][j];
		}
		D[i][R] = min(D[i - 1][G], D[i - 1][B]) + cost[i][R];
		D[i][G] = min(D[i - 1][R], D[i - 1][B]) + cost[i][G];
		D[i][B] = min(D[i - 1][R], D[i - 1][G]) + cost[i][B];
	}
	cout << min(min(D[n][R], D[n][G]), D[n][B]);

	return 0;
}