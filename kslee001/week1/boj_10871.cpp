#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    unsigned int N, X;
    cin >> N >> X;

    for (int i=0; i<N; i++)
    {
        int element;
        cin >> element;
        
        if (element < X)
        {cout << element << ' ';}
    }
}