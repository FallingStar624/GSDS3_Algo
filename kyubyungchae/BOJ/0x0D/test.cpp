#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ind;

int main() {

    for(int i =0; i< 2; i++) {
        ind.push_back(0);
    }

    for(int i=0;i<3;i++) {
        ind.push_back(1);
    }
    for(int i=0;i<1;i++) {
        ind.push_back(2);
    }


    do {
        for(int i =0; i < ind.size(); i++) {
            cout << ind.at(i) << " ";
        }
        cout << "\n";
    } 
    while(next_permutation(ind.begin(), ind.end()));



}