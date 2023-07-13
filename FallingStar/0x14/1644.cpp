#include <iostream>
#include <vector>
using namespace std;

int i, N, ans=0;
vector<int> nums;

void isPrime(int target) {
    if (target <= 1) return;
    for (int i = 2; i * i <= target; i++) {
        if (target % i == 0)
            return;
    }
    nums.push_back(target);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    if (N == 1) {
        cout << 0;
        return 0;
    }
    for (i=0; i<N+1; i++) {
        isPrime(i);
    }
    int p1, p2=0;
    int sum=nums[0];
    for (p1=0; p1<nums.size(); p1++) {
        while ((p2<nums.size()) && sum<N) {
            p2++;
            if (p2!=nums.size()) sum += nums[p2];
        }
        if (p2==nums.size()) break;
        if (sum==N) {
            ans++;
        }
        sum -= nums[p1];
    }
    cout << ans;
    return 0;
}
