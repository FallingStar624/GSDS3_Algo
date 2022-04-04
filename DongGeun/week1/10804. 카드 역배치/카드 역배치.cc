#include <bits/stdc++.h>
using namespace std;
int arr[21];

int main(void) {
    for(int i = 0; i < 21; i++) 
    {
        arr[i]=i;
    }
    int first,last;
    for (int j=0;j<10;j++)
    {
        cin>>first>>last;
        int a=first;
        int b=last;
        for (int k=a;k<=(first+last)/2;k++)
        {
            int temp = arr[b];
            arr[b] = arr[a];
            arr[a] = temp;
            b--;
            a++;
        }
    }
    for(int i = 1; i < 21; i++) 
    {
        cout<<arr[i]<<' ';
    }
    
}