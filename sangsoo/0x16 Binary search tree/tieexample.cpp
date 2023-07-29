#include <iostream>
#include <tuple>
using namespace std;

int main(){
    auto t = make_tuple(1, 2, 3);
    int x = get<0>(t);
    int y = get<1>(t);
    int z = get<2>(t);

    cout << x << ' ' << y << ' ' << z << endl;
    
    x = y = z = 0;
    cout << x << ' ' << y << ' ' << z << endl;
    tie(x, y, z) = t;
    cout << x << ' ' << y << ' ' << z << endl;

    x = y = z = 0;
    std::tie(x, y, ignore) = t; // third position is ignored
    cout << x << ' ' << y << ' ' << z << endl;

    return 0;
} 