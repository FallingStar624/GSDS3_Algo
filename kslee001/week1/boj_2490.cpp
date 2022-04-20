#include <iostream>
using namespace std;


int main(){

    int num_set = 3;
    int num_yut = 4;

    int result[num_set];

    for(int i=0; i<num_set; ++i){
        int sum = 0;

        for(int j=0; j<num_yut; ++j){
            int temp; cin>>temp;
            sum += temp;
        }

        result[i] = sum;
    }

    for(int i=0; i<num_set; ++i){
        switch(result[i]){
            case 0:
                cout << 'D';
                break;
            case 1:
                cout << 'C';
                break;
            case 2:
                cout << 'B';   
                break;
            case 3:
                cout << 'A';
                break;
            case 4:
                cout << 'E';
                break;
        }

        if(i<num_set)
            cout << "\n";
    }
}