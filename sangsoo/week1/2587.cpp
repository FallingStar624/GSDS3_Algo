#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<int> vtr(5);
    int sum = 0;
    for(int i = 0; i<5; i++){
        cin >> vtr[i];
        sum += vtr[i];
    }
    sort(vtr.begin(), vtr.end());
    cout << sum/5 <<endl;
    cout << vtr[2];
}
