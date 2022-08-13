#include <iostream>
#include <algorithm>
using namespace std;

int D[303][3]; // max score when i, with j contiuous steps
int score[303];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	cin >> score[1];
	cin >> score[2];
	D[1][1] = score[1]; D[1][2] = 0;
	D[2][1] = score[2]; D[2][2] = score[1] + score[2];	
	for (int i = 3; i <= n; ++i) {
		cin >> score[i];
		D[i][1] = max(D[i - 2][1], D[i - 2][2]) + score[i];
		D[i][2] = D[i - 1][1] + score[i];
	}
	cout << max(D[n][1], D[n][2]) << '\n';

	return 0;
}