#include <bits/stdc++.h>
using namespace std;
int arr[9];

int main(void) {
    int sum=0;
    for(int i = 0; i < 9; i++) 
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    sort(arr, arr+9);
    int a= sum - 100;
    int rem1,rem2;
    for(int i = 0; i < 9; i++) 
    {
        for(int j = 0; j < 9; j++) 
        {
            if (i!=j)
            {
                if (arr[i]+arr[j]==a)
                {
                    rem1=i;
                    rem2=j;
                    goto EXIT;
                }
            }
                
        }
    }
EXIT:
    for(int k = 0; k < 9; k++) 
    {
        if (k!=rem1&&k!=rem2)
            cout<<arr[k]<<"\n";
    }
    
}
    
