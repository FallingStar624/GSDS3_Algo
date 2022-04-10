#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int n; cin>>n;
    int check[1001];

    string str;
    string str2;
    stringstream ss;
    stringstream ss2;
    char c;
    for(int i=0; i<n; ++i){    
        cin >> str >> str2;

        // array for checking the number of each character 
        // in the given string
        for(int i=0; i<1001; ++i){
            check[i] = 0;
        }

        // first string
        ss.clear(); ss.str(str);
        while(ss>>c){
            check[ (int) c - 97 ] += 1;
        }
        // second string
        ss2.clear(); ss2.str(str2);
        while(ss2>>c){
            check[ (int) c-97 ] -=1 ;
        }        

        // difference check
        bool flag = true;
        for(int j=0; j<1001; ++j){
            if (check[j] != 0) {
                flag = false; break;
            }
        }
        if(flag == false)
            cout << "Impossible";
        else
            cout << "Possible";
        if(i != n-1)
            cout << "\n";
    }



}