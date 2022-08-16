#include <iostream>
#include <algorithm>
using namespace std;


int A[20000];
int B[20000];

int main(){
    int T, n,m;
    cin >>T;
    for(int t=0; t<T; ++t){
        cin >>n>>m;
        cout << "n : "<< n<<" || m : "<< m << "\n";
        for(int i=0; i<n; ++i)
            cin >>A[i];
        for(int i=0; i<m; ++i)
            cin >>B[i];
        sort(A, A+n+1);
        sort(B, B+n+1);

        cout <<"A : \n";
        for(int i=0; i<m; ++i){
            cout << A[i]<<" ";
        }
        cout <<"\n";
        cout <<"B : \n";
        for(int i=0; i<m; ++i){
            cout << B[i]<<" ";
        }
        cout <<"\n";
        
        // 뒤에서 시작
        long long res = 0;
        int cur_cnt = m;
        int* aptr = A+n-1;
        int* bptr = B+n-1;
        cout << "aptr : "<< *aptr << " | bptr : " << *bptr << " | cur_cnt : " <<cur_cnt << "\n";

        while(aptr >=A && bptr >= B){
            if(*aptr >*bptr){
                res += cur_cnt;
                --aptr;
                cout << "aptr : "<< *aptr << " | bptr : " << *bptr << " | cur_cnt : " <<cur_cnt << "\n";
                cout << "-- res plus : " << res-cur_cnt << " + "<< cur_cnt << "\n";           
            }
            else{
                --cur_cnt;
                --bptr;
                cout << "aptr : "<< *aptr << " | bptr : " << *bptr << " | cur_cnt : " <<cur_cnt << "\n";
            }
        }
        cout << res <<"\n";
    }
}