#include <iostream>
#include <algorithm>
using namespace std;

int D[100010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		D[i] = D[i - 1] + num;
	}
	for (int i = 0; i < m; ++i) {
		int ni, nj;
		cin >> ni >> nj;
		cout << D[nj] - D[ni - 1] << '\n';
	}

	return 0;
}