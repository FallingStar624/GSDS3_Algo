#include <iostream>
using namespace std;

int main(){

    int n; cin>>n;
    int count=0;
    for (int i=0; i<n; ++i){
        for(int j=0; j<n-count; ++j){
            cout << '*';
        }
        if(i!= n-1) 
            cout << "\n";
        count++;
    }
    return 0;
}