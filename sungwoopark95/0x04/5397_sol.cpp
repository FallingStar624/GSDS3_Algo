#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int cnt;
    cin >> cnt;
    string arr[cnt];

    for(int i=0;i<cnt;i++) {
        string str;
        cin >> str;
        arr[i] = str;
    }

    for (int i=0;i<cnt;i++) {
        string item = arr[i];

        list<char> pass;
        list<char>::iterator cursor = pass.end();
        for (int j=0;j<(int)item.length();j++) {
            char c = item[j];
            if (c == '<') {
                if (cursor != pass.begin()) {
                    cursor--;
                }
            } else if (c == '>') {
                if (cursor != pass.end()){
                    cursor++;
                }
            } else if (c == '-') {
                if (cursor != pass.begin()) {
                    cursor--;
                    cursor = pass.erase(cursor);
                    // erase 한 번만 하는 이유 <- '-'라는 character에 대한 insert, push_back 등 추가 작업이 없기 때문에
                    // 그냥 -가 나오면 커서 한칸 왼쪽으로 보내서 해당 element 지우게만 하면 끝
                }
            } else {
                pass.insert(cursor, c);
            }
        }

        list<char>::iterator itr;
        for (itr=pass.begin();itr!=pass.end();itr++) {
            cout << *itr;
        }
        cout << "\n";
    }

    return 0;
}