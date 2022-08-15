#include <iostream>
#include <algorithm>
using namespace std;

int d[1000005];
int n;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	d[1] = 0;

	for (int i=2;i<=n;i++) {
		int m = d[i-1] + 1;
		if (i%2 == 0) { m = min(m, d[i/2]+1); }
		if (i%3 == 0) { m = min(m, d[i/3]+1); }
		d[i] = m;
	}
	
	cout << d[n] << "\n";
	return 0;
}