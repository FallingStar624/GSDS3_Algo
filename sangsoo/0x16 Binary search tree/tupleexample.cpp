#include <iostream>
#include <string>
#include <tuple>
using namespace std;

tuple<int, string> getAgeandName(){
    int age;
    string name;
    cout << "Enter your age: ";
    cin >> age;
    cout<< "Enter your name: ";
    cin >> name;

    return tie(age, name); // same with make_tuple (age, name)
}

int main(){
    tuple<int, string> personInfo;
    personInfo = getAgeandName();
    cout << "age : " << get<0>(personInfo) << endl;
    cout << "name : " << get<1>(personInfo) << endl;
    return 0;
} 