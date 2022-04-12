#include <bits/stdc++.h>
using namespace std;

int smallest(string str, int start, int end);
void selection_sort(string &str);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num;
    string a, b;
    
    cin >> num;

    for (int i=0;i<num;i++) {
        cin >> a >> b;

        selection_sort(a);
        selection_sort(b);

        if (a == b) {
            cout << "Possible" << "\n";
        } else {
            cout << "Impossible" << "\n";
        }
    }

    return 0;
}

int smallest(string str, int start, int end) {
    int temp = start;
    for (int i=start;i<end;i++) {
        if (str[temp] > str[i]) {
            temp = i;
        }
    }
    return temp;
}

void selection_sort(string &str) {
    // selection sort
    int small_idx;
    char temp;
    for (int i=0;i<(int)str.length();i++) {
        small_idx = smallest(str, i, (int)str.length());
        if (str[i] > str[small_idx]) {
            temp = str[i];
            str[i] = str[small_idx];
            str[small_idx] = temp;
        }
    }
}