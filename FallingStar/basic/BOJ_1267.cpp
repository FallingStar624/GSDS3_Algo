#include <iostream>

using namespace std;

int young(int time){
    if (time <= 29) return 10;
    else return 10*(time/30 + 1);
}

int min(int time){
    if (time <= 59) return 15;
    return 15*(time/60 + 1);
}


int main() {
    int N;
    cin >> N;
    int y=0;
    int m=0;
    for (int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        y += young(tmp);
        m += min(tmp);
    }
    if (y < m) cout << "Y " << y;
    else if (y > m) cout << "M " << m;
    else cout << "Y M " << y;
    return 0;
}
