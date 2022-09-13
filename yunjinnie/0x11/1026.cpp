// len = N, array A, B -> S = A[0] * B[0] + ... A[N-1]*B[N-1]
// min(S)를 위해 A를 재배열
// 1st row: N <=50
// 2nd row: A elements <=100
// 3rd row: B elements <=100


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
        
    vector<int> a;
    vector<int> b;

    int num1, num2;
    for (int i=0; i<n; i++){
        cin>>num1;
        a.push_back(num1); // 이 경우 a(n) xxx -> seg fault
        //cin>>a[i]; // out of bounds ???
    }
    for (int i=0; i<n; i++){
        cin>>num2;
        b.push_back(num2);
        //cin>>b[i];
    }

    // sort, for vector
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend()); // reverse(begin(), end()) or sort(b.begin(), b.end(), greater<int>());

    int ans=0;
    for (int i=0; i<n; i++){
        ans += a[i]*b[i];
    }

    cout<< ans;
    return 0;

}


// 정렬? 큰 수 * 큰 수는 max이므로 A, B를 단조 감소, 단조 증가로 정렬해줌 (큰 값에 작은 가중치)
// swap -> 더 줄일 수 없을 때 최적
// https://seoftware.tistory.com/35
// https://kking.tistory.com/5