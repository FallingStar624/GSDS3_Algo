// #include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string str="1";
    if(isdigit(str[0])){ //숫자면 1, 숫자아니면 0
        cout<< stoi(str);
    } else {
        cout<<"숫자 아님";
    }
}