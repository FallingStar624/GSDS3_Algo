#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int N, M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    unordered_map<string, string> m;
    for (int i = 0; i < N; i++){
        string cite, pwd;
        cin >> cite >> pwd;
        m[cite] = pwd;
    }
    for (int i = 0; i < M; i++){
        string cite;
        cin >> cite;
        cout << m[cite] << '\n';
    }
}
