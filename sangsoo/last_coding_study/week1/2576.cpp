#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> vtr(7);
    bool isOdd = false;
    int sum = 0;
    int cnt = 0;

    for(int i = 0; i < 7; i ++){
        cin >> vtr[i];
        if(vtr[i]%2){ //vtr[i] is odd
            sum += vtr[i];
            if(!isOdd) isOdd = true;
        }
        else vtr[i] = 0 ; //vtr[i] is even
    }
    if(!isOdd) cout << "-1";
    else{
        sort(vtr.begin(), vtr.end());
        while(!vtr[cnt]){  // cnt ++ until vtr[cnt] isnt't 0
            cnt++;
        }
        cout << sum << "\n" << vtr[cnt];
    }

}