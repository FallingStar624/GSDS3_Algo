#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    vector <int> vtr(21);
    int start, end;

    for(int i =1; i<21; i++){
        vtr[i] = i;
    }
    for(int i=0; i<10; i++){
        cin >> start >> end;
        reverse(vtr.begin()+start, vtr.begin()+end+1);
    }
    for(int i=1; i<21; i++){
        cout << vtr[i] << " ";
    }
    return 0;
}