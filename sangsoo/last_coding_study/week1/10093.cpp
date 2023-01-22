#include <iostream>
using namespace std;
long long A, B;
int main(){
    cin >> A >> B;
    if(B>A){
        cout << B-A-1 << endl;
        for(long long i = A+1; i<B; i++){
            cout << i << " ";
        }
    }
    else if(A>B){
        cout << A-B-1 << endl;
        for(long long i = B+1; i<A; i++){
            cout << i << " ";
        }
    }
    else cout << "0";
    return 0;
}