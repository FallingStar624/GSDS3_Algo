#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int N, S, tot;
int a[100005];
int mn = 0x7fffffff;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    
    for(int i = 0; i < N; i++)
        cin >> a[i];
    
    tot = a[0];
    int en = 0;
    for(int st = 0; st < N; st++) {

        while(en < N && tot < S) {
            en++;
            if(en != N)
                tot += a[en];
        }
        if(en == N)
            break;
        mn = min(mn, en - st + 1);
        tot -= a[st];
    }

    if(mn == 0x7fffffff)
        mn = 0;

    cout << mn;
    return 0;
}