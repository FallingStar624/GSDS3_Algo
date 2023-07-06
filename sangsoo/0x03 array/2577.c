#include <stdio.h>
#include <string.h>
int main(){
    int input, sum = 1;
    int digit;
    int num[10];

    for(int i = 0; i < 10; i++) num[i] = 0;
    for(int i =0; i< 3; i++){
        scanf("%d", &input);
        sum *= input;
    }
    for(int i = 0; sum > 0; i++){
        digit = sum %10;
        num[digit] += 1;
        sum /= 10;
    }
    for(int i = 0; i < 10; i++) printf("%d\n", num[i]);
}
