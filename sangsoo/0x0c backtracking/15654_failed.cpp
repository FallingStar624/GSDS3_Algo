#include <bits/stdc++.h>
using namespace std;

int n, m ;
int arr[10];
vector<int> vec(10);
bool isused[10];

void func(int k){
    if (k == m) { // 현재까지 k개의 수를 택했음.
        for (int i = 0; i < m; i++){ //m개를 모두 택했으면
            cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
        }
        cout << '\n';
        return;
    }
    vector<int>::iterator iter;
    for(iter = vec.begin(); iter != vec.end(); iter++){ // vector에 있는 수에 대해
        if(!isused[*iter]){ //아직 i가 사용되지 않았으면
            arr[k] = *iter; //k번째 수를 i로 정함
            isused[*iter] = 1; // i를 사용했다고 표시
            func(k+1); // 다음수를 정하러 한단계 더 들어감
            isused[*iter] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인 했으니 i를 이제 사용하지 않았다고 명시
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){ // vector로 input을 받음
        cin >> vec[i];
    }
    vec.resize(n); // vector 사이즈를 변경(0값 제거)
    sort(vec.begin(), vec.end()); // vector 정렬
    func(0);
}