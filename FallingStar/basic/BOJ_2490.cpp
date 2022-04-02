#include <iostream>

using namespace std;

int main() {
    int w, x, y, z;
    for (int i=0; i<3; i++) {
        cin >> w >> x >> y >> z;
        int tmp = w+x+y+z;
        if (tmp == 1) cout << 'C' << "\n";
        else if (tmp == 2) cout << 'B' << "\n";
        else if (tmp == 3) cout << 'A' << "\n";
        else if (tmp == 4) cout << 'E' << "\n";
        else cout << 'D' << "\n";
    }
}
