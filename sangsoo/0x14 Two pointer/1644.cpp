#include <bits/stdc++.h>
using namespace std;
int N, st, en, cnt;
int psumarr[4000000];
vector <int> prime;
void Eratos(int n){ // Sieve of Eratosthenes
    int* isprime; 
    //isprime = (int*)malloc(sizeof(int)*(n+1));  // 넉넉하게 할당 ! prime number 1, not prime number 2, not done 0;
    isprime = new int[n+1]; // same with isprime = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i <= n; i++) isprime[i] = 0; // initialization // not done 0;
    int i = 2;
    while (i <= n){
        if (isprime[i]) {i++; continue; }
        else {isprime[i] = 1; prime.push_back(i); } // prime number
        int j = 2;
        while(i*j<=n){
            isprime[i*j] = 2;
            j++;
        }
        i++;
    }
    // free (isprime);
    delete isprime; //malloc-free / new - delete
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    if(N == 1) {cout << "0";return 0;}
    Eratos(N); // Sieve of Eratosthenes

    psumarr[0] = prime[0]; // prefix sum array
    for(int i = 1; i < prime.size(); i++){
        psumarr[i] = prime[i] + psumarr[i-1];
    }
    int partialsum = 0;
    while(st < prime.size()){
        while (en < prime.size()){
            partialsum = (st > 0) ? psumarr[en]-psumarr[st-1] : psumarr[en]; // 음수 인덱스 방지
            if(partialsum == N) {cnt++;break;}
            else if (partialsum > N) break;
            en++;
        }
        st++;
    }
    cout << cnt;
}

/*
int* Eratos(int n){ // Sieve of Eratosthenes
    int* isprime; 
    isprime = (int*)malloc(sizeof(int)*n);  // prime number 1, not prime number 2, not done 0;
    for(int i = 0; i < n; i++) isprime[i] = 0; // initialization // not done 0;

    int i = 2;
    while (i <= n){
        if (isprime[i]) {i++; continue;}
        else isprime[i] = 1; // prime number
        int j = 2;
        while(i*j<=n){
            isprime[i*j] = 2;
            j++;
        }
        i++;
    }

    return isprime;
}
*/