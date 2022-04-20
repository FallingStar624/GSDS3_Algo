#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> student(12);
    for (int i=0; i<n; i++) {
        int s, y;
        cin >> s >> y;
        student[s+2*(y-1)]++;
    }
    int result = 0;
    for (int l: student) {
        if (l==0) {
            continue;
        } else if (l%k == 0) {
            result += l/k;
        } else {
            result += l/k +1;
        }
    }
    cout << result;
    return 0;
}
