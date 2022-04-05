#include <iostream>
#include <stdio.h>
using namespace std;
static bool sync_with_stdio(bool sync = false);
int main()
{
    cin.tie(NULL);
    int N; cin >> N;

    char s = '*'; char b = ' ';
    for (int i=1; i < N+1; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(j<N-i)
            {
                cout << b;
            }
            else
            {
                cout << s;
            }
        }
    if (i!= N)
        {cout << endl;}
    }
}