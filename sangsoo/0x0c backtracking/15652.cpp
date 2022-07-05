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
    if(k != 0) st = arr[k-1] ; // k !=0 이면 st = arr[k-1] , 이전 숫자 부터 , 같은수를 뽑아도 되니까
    for(int i = st; i <= n; i++){
        if(!isused[i]){ // 아직 i가 사용되지 않았으면
            arr[k] = i; // k번째 수를 i로 정함
            func(k+1); // 다음 수를 정하러 한 단계 더 들어감
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}

