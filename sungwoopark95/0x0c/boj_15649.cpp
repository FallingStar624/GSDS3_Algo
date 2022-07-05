#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k) { // k: 현재 state에서 선택한 숫자의 개수
	if (k == m) { // m개를 모두 선택한 경우
		for (int i=0;i<m;i++) { cout << arr[i] << " "; } // array에 기록된 수 모두 출력
		cout << "\n";
		return;
	}
	// 아직 m개를 모두 선택하지 않은 경우
	for (int i=1;i<=n;i++) { // 1부터 n까지의 수 중에서
		if (!isused[i-1]) {
			arr[k] = i; // 현재 state에서 i를 선택
			isused[i-1] = 1; // isused를 true로 변경
			func(k+1); // 다음 수열에 오는 숫자를 위해 한 단계 더 밑으로
			isused[i-1] = 0; // 다음 단계를 끝낸 다음 다시 돌아왔을 때, 그때는 다시 사용될 수 있어야 함
		}
  }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	func(0);
}