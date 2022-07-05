#include <bits/stdc++.h>
using namespace std;

int n, m ;
int arr[10];
bool isused[10];
int num[10];

void func(int k){
    if (k == m) { // 현재까지 k개의 수를 택했음.
        for (int i = 0; i < m; i++){ //m개를 모두 택했으면
            cout << num[arr[i]] << ' '; // arr에 기록해둔 인덱스에 대응되는 수를 출력
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){  
        if(!isused[i]){ //아직 i가 사용되지 않았으면
            arr[k] = i; //k번째 인덱스를 i로 정함
            func(k+1); // 다음수를 정하러 한단계 더 들어감
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