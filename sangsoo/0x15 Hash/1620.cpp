#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int N, M;

bool isNumber(const string &str){
    for (char  const &c : str){
        if (isdigit(c) == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    unordered_map<string, int> si_m; // stoi 로 명명하면 stoi 함수랑 겹침
    unordered_map<int, string> is_m;
    int idx = 1;
    for(int i = 0; i < N; i++){
        string name;
        cin >> name;
        si_m[name] = idx;
        is_m[idx] = name;
        idx += 1;  // 실수 주의
    }
    for (int i = 0; i < M; i++){
        string in;
        cin >> in;
        if (isNumber(in)) {
            int num = stoi(in);
            cout << is_m[num] << '\n';
        }
        else{
            cout << si_m[in] << '\n';
        }
    }
}