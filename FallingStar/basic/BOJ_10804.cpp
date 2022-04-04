#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> v(21);
    for (int i=0; i<21; i++) {
        v[i] = i;
    }

    for (int i=0; i<10; i++) {
        int start;
        int end;
        cin >> start >> end;
        for (int j=start; j<(start+end+1)/2; j++){
            swap(v[j], v[start+end-j]);
        }
    }
    for (int k=1; k<20; k++) {
        cout << v[k] << " ";
    }
    cout << v[20];

    return 0;
}

