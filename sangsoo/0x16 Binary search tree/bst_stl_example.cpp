#include <iostream>
#include <set> // multiset 포함
#include <map>
using namespace std;
// set은 자동으로 정렬해지는  Red black tree것
void set_example(){
    set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); // {-10, 15, 100}
    s.insert(-10); // {-10, 15, 100}
    cout << s.erase(100) << '\n'; // {-10,, 15}, 1
    cout << s.erase(20) << '\n'; // {-10,, 15}, -0
    if(s.find(15) != s.end()) cout << "15 in s \n";
    else cout << "15 not in s \n";
    cout << s.size() << '\n'; // 2
    cout << s.count(50) << '\n'; // 0
    for (auto e : s) cout << e << ' ';
    cout << '\n';
    s.insert(-40); // {-40, -10, 15}
    set<int>::iterator it1 = s.begin(); // {-40(<-it1), -10, 15}
    it1++; // {-40, -10(<-it1), 15}
    auto it2 = prev(it1); // {-40(<-it2), -10, 15}
    it2 = next(it1); // {-40, -10, 15(<-it2)}
    advance(it2, -2); // {-40(<-it2), -10, 15}
    auto it3 = s.lower_bound(-20); // {-40, -10(<-it3), 15}
    auto it4 = s.find(15); // {-40, -10, 15(<-it4)}
    auto it5 = s.find(9); // 
    auto it6 = s.find(100); // 
    auto it7 = s.end(); // 
    cout << *it1 << '\n'; // -10
    cout << *it2 << '\n'; // -40
    cout << *it3 << '\n'; // -10
    cout << *it4 << '\n'; // 15 
    cout << *it5 << '\n'; // 3
    cout << *it6 << '\n'; // 3
    cout << *it7 << '\n'; // 3
}

void multiset_example(){
    multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); 
    ms.insert(-10); ms.insert(15); //{-10, -10, 15, 15, 100}
    cout << ms.size() << '\n'; // 5
    for(auto e : ms) cout << e << ' ';
    cout << '\n';
    cout << ms.erase(15) << '\n'; //{-10, -10, 100}, 2
    ms.erase(ms.find(-10)); // {-10, 100}
    ms.insert(100); // {-10, 100, 100}
    cout << ms.count(100) << '\n'; // 2
    auto it1 = ms.begin(); // {-10(<-it1), 100, 100}
    auto it2 = ms.upper_bound(100); //{-10, 100, 100} (<-it2)
    auto it3 = ms.find(100); // {-10, 100(<-it3), 100}
    cout << *it1 << '\n'; // -10
    cout << (it2 == ms.end()) << '\n';
    cout << *it3 << '\n'; // 100;
    cout << *it2 << '\n'; // ?
}

void map_example(){
    map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] =165; // ("bkd", 1000), ("gogo", 165), ("hi", 123)
    cout << m.size() << '\n'; // 3
    m["hi"] = -7; // ("bkd", 1000), ("gogo", 165), ("hi", -7)
    if(m.find("hi") != m.end()) cout << "hi in m\n";
    else cout << "hi not in m\n";
    m.erase("bkd"); // ("gogo", 165), ("hi", -7)
    for(auto e : m)
        cout << e.first << ' ' << e.second << '\n';
    auto it1 = m.find("gogo");
    cout << it1->first << ' ' << it1->second << '\n'; // gogo 165
}


int main(){
    cout << "set_example" << endl;
    set_example();
    cout << "multiset_example" << endl;
    multiset_example();
    cout << "map_example" << endl;
    map_example();
}