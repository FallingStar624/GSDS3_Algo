#include <iostream>
using namespace std;

int par[100002];
int sum[100002];
int prefixsum[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m; // 직원수, 칭찬수
    for(int i = 1; i <= n; i++){ // 부모 설정
        int p; cin >> p;
        par[i] = p;
    }
    for(int i = 0; i < m; i++){ // 본인이 받은 칭찬
        int idx, w;
        cin >> idx >> w;
        sum[idx] += w; // 한사람이 여러번 받을 수 있음 이거때문에 여러번 틀림
    }
    for (int i = 2; i <= n; i++){
        prefixsum[i] = sum[i] + prefixsum[par[i]] ; // 본인 칭찬 : 본인이 받은 칭찬 + 본인 부모가 받은 칭찬
    }
    for (int i = 1; i <= n; i++){
        cout << prefixsum[i] << ' ';
    }

}