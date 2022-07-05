// 15663 + 15650 문제 응용버전
#include <bits/stdc++.h>
using namespace std;

int n, m ;
int arr[10];
bool isused[10];
int num[10];
int idx[10];

void func(int k){
    if (k == m) { // 현재까지 k개의 수를 택했음.
        for (int i = 0; i < m; i++){ //m개를 모두 택했으면
            cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
        }
        cout << '\n';
        return;
    }
    int st = 0; // k=0 이면 st = 0 부터
    if(k != 0) st = idx[k-1]+1; // 전번(k-1) 숫자 다음 부터 
    int tmp = 0; // 중복 수열인지 확인하기 위해 필요한 임시 변수
    for(int i = st; i < n; i++){  
        if(!isused[i] && tmp != num[i]){ //아직 i가 사용되지 않았으면 + num[i-1] != num[i] 이면
            idx[k] = i; // func(k)에대한 index 저장
            arr[k] = num[i]; // k번째 인덱스를 num[i]로 정함
            isused[i] = 1; // i를 사용했다고 표시
            tmp = arr[k];
            func(k+1); // 다음수를 정하러 한단계 더 들어감
            isused[i] = 0; // k번째 인덱스를 i로 정한 모든 경우에 대해 다 확인 했으니 i를 이제 사용하지 않았다고 명시
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){ // num[]로 input을 받음
        cin >> num[i];
    }
    sort(num, num+n); // 정렬
    func(0);
}