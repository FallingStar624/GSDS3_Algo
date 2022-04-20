#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int get_digit(string str){
    stringstream ss(str); 
    char temp;
    int len = 0;
    while(ss>>temp){
        len++;
    }
    return len;
}

// big number -> string -> char -> int array( return : pointer)
int *make_array(string str, int len, int padding){
    int *arr = new int[len];
    // padding for smaller number
    for(int i=0; i<padding; ++i){
        arr[i] = 0;
    }
    
    // insert every single numbers into array
    char temp;
    stringstream ss(str);
    for(int i=padding; i<len; ++i){
        ss>>temp;
        arr[i] = (int) temp -48;
    }
    // return the pointer of newly generated array 
    return arr;
}

void print_array(int arr[], int len){
    bool flag = false;
    for(int i=0; i<len;++i){
        if(arr[i]!=0)
            flag= true;
        if(flag==true)
            cout<< arr[i];
    }
}

void add_print_array(int big[], int small[], int len){
    int* arr = new int[len];
    int val = 0; int carry = 0;
    for(int i=len-1; i>=0; --i){
        val = big[i] + small[i] + carry;
        if(val>=10){
            val-=10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        arr[i] = val;
    }
    if(carry == 1){
        cout<<"1";
        print_array(arr, len);
    }
    else{
        print_array(arr, len);
    }

    delete[] arr;
}

int get_differ(int big[], int small[], int len){
    int* arr = new int[len];
    int val = 0; int carry = 0;
    for(int i=len-1; i>=0; --i){
        val = big[i] - small[i] - carry;
        if(val<0){
            val+=10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        arr[i] = val;
    }
    int difference = 0;
    int digit = 1;
    for(int i=len-1; i>=0; --i){
        difference += arr[i]*digit;
        digit*=10;
    }
    return difference;
}


int main(){

    string b;
    string a;
    cin >> a>> b;

    if(a>b){
        string temp = a;
        a = b;
        b = temp;
    }
    else if (a==b){
        cout << 0;
        return 0;
    }

    int len = get_digit(b);
    int padding = len - get_digit(a);
    int* small_arr = make_array(a, len, padding);
    int* big_arr = make_array(b, len, 0);
    // add_print_array(big_arr, small_arr, len);
    int differ = get_differ(big_arr, small_arr, len);

    cout << differ-1 << "\n";
    for(int i=1; i<differ; ++i){
        int tem = i;
        string add = to_string(tem);
        int padding_2 = len - get_digit(add);
        int* add_arr = make_array(add, len, padding_2);
        add_print_array(small_arr, add_arr, len);
        cout << " ";
        delete add_arr;
    }

    
}
