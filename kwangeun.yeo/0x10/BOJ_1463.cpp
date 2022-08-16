#include <iostream>
#include <algorithm>
using namespace std;

int D[1000010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	D[1] = 0;
	for (int i = 2; i <= n; ++i) {
		D[i] = D[i - 1] + 1;
		if (!(i % 2)) D[i] = min(D[i], D[i / 2] + 1);
		if (!(i % 3)) D[i] = min(D[i], D[i / 3] + 1);
	}
	cout << D[n];

	return 0;
}