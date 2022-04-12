#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        vector<int> temp1(26), temp2(26);
        string str1, str2;
        cin >> str1 >> str2;
        for (char j: str1) temp1[int(j)-97]++;
        for (char k: str2) temp2[int(k)-97]++;
        if (temp1 == temp2) cout << "Possible" << "\n";
        else cout << "Impossible" << "\n";
    }
    return 0;
}
