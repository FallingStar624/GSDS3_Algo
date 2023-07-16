/*  
    문제를 이해하는데 오래걸림
    (N+1)*(M+1) -1 임
    (옷의 종류 + 아예 안입은 경우) * (옷의 종류 + 아예 안입은 경우) - 1(둘다 안입은 경우)
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++){
            string clothes, type;
            cin >> clothes >> type;
            if (m.find(type) != m.end()) m[type] += 1; // type이라는 키가 있으면
            else m[type] = 2; // 없으면 아예 안입은 경우를 포함
        }
        int out = 1;
        for(auto e : m){
            out *= e.second;
        }
        cout << out -1 << '\n';
    }
}