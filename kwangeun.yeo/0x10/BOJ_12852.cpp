#include <iostream>
#include <algorithm>
using namespace std;

int D[1000010];
int pre[1000010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		D[i] = D[i - 1] + 1;
		pre[i] = i - 1;
		if (!(i % 2) && D[i] > D[i / 2] + 1) {
			D[i] = D[i / 2] + 1;
			pre[i] = i / 2;
		}
		if (!(i % 3) && D[i] > D[i / 3] + 1) {
			D[i] = D[i / 3] + 1;
			pre[i] = i / 3;
		}
	}
	cout << D[n] << '\n';
	int num = n;
	while (num >= 1) {
		cout << num << ' ';
		num = pre[num];
	}

	return 0;
}