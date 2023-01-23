#include <iostream>
#include <string>

using namespace std;

int occur[10];

int main() {

    string input;

    cin >> input;

    for(char c : input) {
        occur[c - '0']++;
    }

    int num;
    int answer = 0;
    for(int i = 0; i < 10; i++) {
        if(i == 6 || i == 9)
            continue;
        answer = max(answer, occur[i]);
    } 

    answer = max(answer, (occur[6] + occur[9] + 1)/2);

    cout << answer;

    return 0;
}