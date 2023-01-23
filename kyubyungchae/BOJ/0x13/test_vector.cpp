#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<string> vec;
list<int> lst;

int main(void) {

    string str1 = "Hello";
    string str2;
    string str3;

    str3 = "world!";
    str2 = "c++";

    vec.push_back(str1);
    vec.push_back(str2);
    vec.push_back(str3);

    list<int>::iterator it;
    lst.push_front(1);
    lst.push_back(2);
    lst.push_front(3);

    for(int i=0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    for(it=lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << "." << endl;

    return 0;
}



