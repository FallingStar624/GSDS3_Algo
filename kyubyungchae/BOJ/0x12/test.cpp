#include <iostream>
#include <algorithm>
using namespace std;

int t;
//bool prime;
//int arr[1000002] = {0, };

// euclid algorithm
int gcd(int a, int b){
    // swap
    if (a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (b>0){
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
} // or recursive -> if b==0 return a; else return gcd(a, a%b);

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;

    int m, n, x, y;
    int ans=1;

    while(t--){
        cin>>m>>n>>x>>y;
        int lim = lcm(m, n);
        //if (x==m) 1로 설정? loop 1st

        // 가능한 연도 값에서 search
        for (int i=x; i<=lim; i+=m){
            /*
            if (i==m) {
                i=1;
                ans++;
            }
            else if (j==n) {
                j=1;
                ans++;
            }
            else if (i==x && j==y) cout<<ans<<'\n'; */
            // x*m
            int j = i%n;
            //if (j==0) j = n;
            if (j==y) {
                ans = i;
                break;
            }
            else ans = -1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}