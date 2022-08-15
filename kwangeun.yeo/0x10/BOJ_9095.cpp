#include <iostream>
#include <algorithm>
using namespace std;

int D[12];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	D[1] = 1; 
	D[2] = 2; 
	D[3] = 4;
	for (int i = 4; i <= 10; ++i) {
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}

	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int n;
		cin >> n;
		cout << D[n] << '\n';
	}

	return 0;
}