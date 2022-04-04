#include <iostream>
using namespace std;
int main(void) 
{
    int a;
    cin >> a;
    if (a>=90&&a<=100)
    {
        cout<<"A\n";
    }
    else if (a>=80&&a<90)
    {
        cout<<"B\n";
    }
    else if (a>=70&&a<80)
    {
        cout<<"C\n";
    }
    else if (a>=60&&a<70)
    {
        cout<<"D\n";
    }
    else
        cout<<"F\n";

}