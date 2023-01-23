#include <iostream>
#include <string>
#include <list>

using namespace std;


string findpw(string text) {
    list<char> L;
    auto cursor = L.begin();

    for(char c : text) {
            
        if(c == '-') {
            if(cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        } else if(c == '<') {
            if(cursor != L.begin()) 
                cursor--;
        } else if(c == '>') {
            if(cursor != L.end())
                cursor++;
        } else {
            L.insert(cursor, c);
        }
    }
    string output = "";
    for(char c : L) {
        output += c;
    }
    return output;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    string inputArr[N];
    
    for(int i = 0; i < N; i++) {
        cin >> inputArr[i];
    }
    
    for(string text : inputArr) {
        cout << findpw(text) << '\n';  
    }

    return 0;
}