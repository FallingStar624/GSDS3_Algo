#include <iostream>
#include <list>

using namespace std;
int main()
{
    // 리스트 생성
    list<int> a;

    // 원소 추가
    a.push_back(22); // 22
    a.push_back(33); // 22 33
    a.push_front(11); // 11 22 33 
    a.push_back(44); // 11 22 33 44
    a.push_back(55); // 11 22  33 44 55

    // 반복자 생성
    auto t = a.begin(); // t 11 가리킴
    cout<< *t << "*t" << endl; // 22

    // 리스트 출력
    for (auto i : a)     cout << i << " "; // 11 22  33 44  55
    cout << endl;

    a.pop_front(); // 22 33 44 55
    a.pop_back(); // 22 33 44
    for (auto i : a)     cout << i << " "; // 11 22  33 44  55
    cout<< *t << "*t" << endl; // 22

    for (auto i :a)     cout << i << " " ;
    cout << a.size() <<endl;  // 3
    cout << a.empty() <<endl; // false
    cout << a.front() <<endl; // 22
    cout << a.back() <<endl; // 44
    cout<< *t << "*t" << endl; // 22
    t++; // 33
    cout<< *t << "*t" << endl; // 22

    t++; // 44
    cout<< *t << endl; //44
    a. insert(t, 555); // 22 33 555 44
    for (auto i :a)     cout << i << endl;
}