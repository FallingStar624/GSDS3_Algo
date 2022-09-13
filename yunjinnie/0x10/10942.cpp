// palindrome -> 1 / 0
// 1<=S<=E<=N, S~E -> M questions
// 1st row: 1<=N<=2000
// 2nd row: sequence N, each <=100,000
// 3rd row: 1<=M<=1000000
// 4th row ~ Mth row: S, E (index) 

#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m;
int num[2002];
//int idx[100002];
int st, en;
bool d[2002][2002] = {0, }; 
bool ans;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for (int i=1; i<=n; i++){ // 0~n xxx -> given index >=1
        cin>>num[i];
    }

    for (int i=1; i<=n; i++){
        // 1자리
        d[i][i] = 1;
        // 2자리
        if (num[i]==num[i+1]) d[i][i+1] = 1;

    }

    for (int i=2; i<=n; i++){
        for (int j=1; i+j<=n; j++){
            if (num[j]==num[i+j] && d[j+1][i+j-1]==1) d[j][i+j]=1;

        }
    }

    cin>>m;

    for (int i=0; i<m; i++){
        cin>>st>>en;
        //for (int j=st; j<=en; st++, en--){
            //if (num[st] != num[en]) d[st][en]=0;
            //else d[st][en]=1;
        //}
        cout<<d[st][en]<<'\n';
    }

    //for (int i=0; i<m; i++){
    return 0;
}

// 입력받을 때마다 검사하면 연산 횟수 20억번 -> time complexity 초과
// n[s] = n[e] -> n[s+1] = n[e-1] : 3자리 이상부터 해당
// n[s] == n[e] && d[s+1][e-1] == true
// https://cocoon1787.tistory.com/326