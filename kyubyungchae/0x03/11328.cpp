#include <iostream>
#include <string>

using namespace std;



string compare(string str1, string str2) {

    int occur[1001] = {};

    for(char c : str1) {
        occur[c - 'a']++; 
    }

    for(char c : str2) {
        occur[c - 'a']--; 
    }

    for(int i = 0; i < 1001; i++) {
        if(occur[i] != 0) {
            return "Impossible";
        }
    }
    return "Possible";

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string arr[N][2];
    for(int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 0; i < N; i++) {
        cout << compare(arr[i][0], arr[i][1]) << '\n';  
    }

    return 0;
}