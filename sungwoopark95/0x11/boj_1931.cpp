#include <iostream>
#include <algorithm>
using namespace std;

int N, answer;
int A[55];
int B[55];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) { cin >> A[i]; }
    for (int i=0;i<N;i++) { cin >> B[i]; }
    
    sort(A, A+N);
    sort(B, B+N);
    
    for (int i=0;i<N;i++) { answer += (A[i] * B[N-1-i]); }
    cout << answer << "\n";
    
    return 0;
}