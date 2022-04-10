#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;


int main(){
    string str1, str2;
    char c1, c2;
    cin >>str1 >>str2;
    stringstream ss1(str1);
    stringstream ss2(str2);


    // array for checking the number of each character
    // in the given strings
    int check1[1001];
    int check2[1001];
    for(int i=0; i<1001; ++i){
        check1[i] = 0;
        check2[i] = 0;
    }

    while(ss1>>c1){
        check1[ (int) c1-97 ] +=1; 
    }
    while(ss2>>c2){
        check2[ (int) c2-97 ] +=1;
    }

    int cnt =0;
    for(int i=0; i<1001;++i){
        cnt = cnt + abs(check1[i] - check2[i]);
    }
    cout << cnt;
}