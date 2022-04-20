#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;

    cin >> N >> K;

    list<int> L;

    for(int i = 0; i < N; i++) {
        L.push_back(i+1);
    }

    auto cursor = L.begin();
    int length = N;
    cout << "<";
    while(!L.empty()) {
        for(int i = 0; i < K - 1; i++) {
            if(cursor == L.end()) {
                cursor = L.begin();
                cursor++;
            } else {
                cursor++;
            }
            
        }
        cout << *cursor << ", ";
        cursor = L.erase(cursor);
        
        length--;
        if(length < K) {
            for(auto it = L.begin(); it != L.end(); it++){
                if(*it == L.back()){
                    cout << *it;
                } else {
                    cout << *it << ", ";
                }
                
            }
            break;
        }
        
    }
    cout << ">";
    
    // 1 2 *3 4 5 6 7
    // 1 2 4 5 *6 7
    // 1 *2 4 5 7
    // 1 4 5 *7
    // 1 4 *5
    // 1 4

    return 0;
}