#include <iostream>
#include <algorithm>
using namespace std;

int D[1002];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= n; ++i) {
		D[i] = (D[i - 1] + D[i - 2]) % 10007;
	}
	cout << D[n];

	return 0;
}