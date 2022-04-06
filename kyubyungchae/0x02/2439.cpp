#include <iostream>
#include <stdio.h>
using namespace std;


int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    for (int i = 1; i < N+1; i++)
    {
        for (int j = 1; j < N + 1; j++) {
            if (j <= N - i) {
                cout << ' ';
            } else {
                cout<< '*';
            }
            
        }
        cout<< endl;    
    }
}