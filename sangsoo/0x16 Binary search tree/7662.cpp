#include <iostream>
#include <set>
using namespace std;
int T;
int main(){
    cin >> T;
    while (T--){
        int k;  
        cin >> k;
        multiset<int> ms;
        while(k--){
            char c; int n;
            cin >> c >> n;
            if (c == 'I') ms.insert(n); // single quotes 로 해야한다!!
            else{
                if (ms.size() == 0) continue;
                if (n == 1) ms.erase(prev(ms.end()));
                else ms.erase(ms.begin());
            }

        }
        if (ms.size() == 0) cout << "EMPTY" <<  '\n';
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }

}