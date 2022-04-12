#include <bits/stdc++.h>
using namespace std;

void digit_cnt(string str);
int find_max(int *arr, int size);
int abs(int x);
int cnt[10];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 0~9까지의 배열을 잡아서, 등장한 횟수 전부 count
    // maximum 값의 개념으로 접근
    int N;
    cin >> N;
     
    string Nstr = to_string(N);

    digit_cnt(Nstr);
    int maxcnt = find_max(cnt, 10);

    if ((cnt[6] != maxcnt) & (cnt[9] != maxcnt)) {
        // if argmax is neither 6 nor 9, print the maximum
        cout << maxcnt << "\n";
    } else if (cnt[6] == cnt[9]) {
        // if argmax is both 6 and 9, also print the maximum
        cout << maxcnt << "\n";
    } else {
        // if either 6 or 9 is the argmax
        int other_argmax = 0;
        int diff;
        for (int i=0;i<10;i++) {
            if (maxcnt == cnt[i]) {
                other_argmax++;
            }
        }
        // if there is another argmax
        if (other_argmax > 1) {
            cout << maxcnt << "\n";
        } else {
            // either 6 or 9 is the only argmax
            diff = abs((cnt[6] - cnt[9]));
            cout << maxcnt - (diff / 2) << "\n";
        }
    }

    return 0;
}

void digit_cnt(string str) {
    char digit;
    for (int i=0;i<(int)str.length();i++) {
        digit = str[i];
        cnt[digit-'0'] += 1;
    }
}

int find_max(int *arr, int size) {
    int maximum = arr[0];
    for (int i=1;i<size;i++) {
        if (maximum < arr[i]) {
            maximum = arr[i];
        }
    }
    return maximum;
}

int abs(int x) {
    if (x >= 0) {return x;}
    else {return (-1) * x;}
}