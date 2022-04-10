#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int n; cin >>n;   // number of students
    int mp; cin >>mp; // maximum number of students per room

    int grade = 6; int sex;
    int female[grade];
    for(int i=0; i<grade; ++i){
        female[i] = 0;
    }
    int male[grade];
    for(int i=0; i<grade; ++i){
        male[i] = 0;
    }

    int grade_temp;  
    for(int i=0; i<n; ++i){
        cin >> sex >> grade_temp;
        if(sex ==0)
            female[grade_temp-1] ++;
        else
            male[grade_temp-1] ++;
    }

    int room=0;
    for(int i=0; i<grade; ++i){
        room += ceil( (float) male[i]/(float) mp);
    }
    for(int i=0; i<grade; ++i){
        room += ceil( (float) female[i]/(float) mp);
    }
    cout << room;
}