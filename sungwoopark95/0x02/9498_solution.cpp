#include <iostream>
using namespace std;

int main() {
    int grade;
    cin >> grade;

    if (grade >= 90 & grade <= 100) { cout << "A" << endl; }
    else if (grade >= 80) { cout << "B" << endl; }
    else if (grade >= 70) { cout << "C" << endl; }
    else if (grade >= 60) { cout << "D" << endl; }
    else { cout << "F" << endl; }

    return 0;
}