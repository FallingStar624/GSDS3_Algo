// copy solution 
#include <bits/stdc++.h>
using namespace std;

int n, m ;
int arr[10];
bool isused[10];

void func(int k){ // 현재 k개까지 수를 택했음
    if (k == m) { // m개를 모두 선택하면
        for (int i = 0; i < m; i++){
            cout << arr[i] << ' '; // arr 에 저장된 수를 출력
        }
        cout << '\n';
        return;
    }
    int st = 1; // 시작지점, k = 0일때는 st = 1
    if(k != 0) st = arr[k-1] +1; // k !=0 이면 st = arr[k-1] +1 이전 숫자 + 1 부터
    cout << "st : " << st << " = " << "arr[" << k-1 << "]  "<<  " k : " << k << '\n';
    for(int i = st; i <= n; i++){
        cout << "-- k = " << k << " i = " << i << " --" << '\n';
        if(!isused[i]){ // 아직 i가 사용되지 않았으면
            cout << "arr[" << k << "] = " << i << '\n';
            arr[k] = i; // k번째 수를 i로 정함
            cout << "isused[" << i << "] = " << 1 << '\n';
            isused[i] = 1; // i를 사용되었따고 표시
            cout << "func(" << k+1 << ")" << '\n';
            func(k+1); // 다음 수를 정하러 한 단계 더 들어감
            cout << "finish func(" << k+1 << ") " << '\n'; 
            cout << "isused[" << i << "] = 0" << '\n'; 
            isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 이제 i를 사용하지 않았다고 표시
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}

