#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(7);
    v.push_back(6);
    for(int i = 0; i< v.size(); i++) cout << v[i] << ' ';
    cout << endl;

    unique(v.begin(), v.end());
    for(int i = 0; i< v.size(); i++) cout << v[i] << ' ';
    cout << endl;
    sort(v.begin(), v.end());
    for(int i = 0; i< v.size(); i++) cout << v[i] << ' ';
    cout << endl;

    unique(v.begin(), v.end());
    for(int i = 0; i< v.size(); i++) cout << v[i] << ' ';
    cout << endl;
    
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i< v.size(); i++) cout << v[i] << ' ';
    cout << endl;
}