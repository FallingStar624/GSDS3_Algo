#include <bits/stdc++.h>
using namespace std;


int n; // 길이
int c; // 문자 종류

char print[15];
bool used [15];

int  raw[15];
char sorted[15];

void input(){
    cin >> n >> c;
    char input;
    for(int i=0; i<c; ++i){
        cin >> input;
        raw[i] = (int)input;
    }
    sort(raw, raw+c);
    for(int i=0; i<c; ++i){
        sorted[i] = (char) raw[i];
    }
}

int conso_cnt = 0;
int vowel_cnt = 0;

void func(int k, int prev_idx){
    if(k==n){
        if( conso_cnt >=2 && vowel_cnt >=0 ){
            for(int i=0; i<n; ++i){
                printf("%c", print[i]);
            }printf("\n");

        }
        conso_cnt = 0;
        vowel_cnt = 0;
        return;
    }


    char prev = '0';
    for(int i=prev_idx+1; i<c; ++i){
        if(prev != sorted[i]){
            print[k] = sorted[i];
            // used[i]  = true;
            prev = sorted[i];
            if(sorted[i] == 'a') vowel_cnt++;
            else if(sorted[i] == 'e') vowel_cnt++;
            else if(sorted[i] == 'i') vowel_cnt++;
            else if(sorted[i] == 'o') vowel_cnt++;
            else if(sorted[i] == 'u') vowel_cnt++;
            else conso_cnt ++;
            func(k+1, i);
            // used[i] = false;
        }
    }
}




int main(){
    input();
    // cout << (prev == sorted[0]);

    func(0, -1);


}