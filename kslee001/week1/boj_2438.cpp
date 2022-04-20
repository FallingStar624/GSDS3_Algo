#include <iostream>
#include <stdio.h>
using namespace std;
static bool sync_with_stdio(bool sync = false);
int main()
{
    cin.tie(NULL);
    int N; cin >> N;
    char a = '*';

    for (int i=1; i<N+1; i++)
    {
        for (int i2 = 1; i2<i+1; i2++)
            {cout<< a;}
        if (i != N)
            cout<< endl;
    }
}