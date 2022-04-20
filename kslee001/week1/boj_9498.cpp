#include <iostream>
using namespace std;
int main(){
    int A;
    cin >> A;
    if((90<=A) && (A<=100))
    {cout<<"A";}
    else if((80<=A) && (A<=89))
    {cout<<"B";}
    else if((70<=A) && (A<=79))
    {cout<<"C";}
    else if((60<=A) && (A<=69))
    {cout<<"D";}
    else
    {cout<<"F";}
}