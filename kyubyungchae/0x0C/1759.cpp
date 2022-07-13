#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char val[15];
char arr[15];
bool isused[15];

bool aeiou(char t){
  return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

void func(int k) {
    if(k == l) {
        bool isPrint = false;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i < l; i++) {
            if(aeiou(arr[i])) cnt1++;
            else cnt2++;
        }

        if(cnt1 >= 1 && cnt2 >= 2)
            isPrint = true;

        if(isPrint) {
            for(int i = 0; i < l; i++)
                cout << arr[i];
            cout << "\n";
        }
        return;
    }

    char tmp = 'a' - 1;
    char succesor = 'a' - 1;
    if(k > 0)
        succesor = arr[k-1];

    for(int i = 0; i < c; i++) {
        if(!isused[i] && (tmp != val[i]) && (val[i] >= succesor)) {
            arr[k] = val[i];
            isused[i] = 1;
            tmp = val[i];
            func(k+1);
            isused[i] = 0;     
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;

    for(int i = 0; i < c; i++) {
        cin >> val[i];
    }

    sort(val, val+c);

    func(0);

    return 0;
}