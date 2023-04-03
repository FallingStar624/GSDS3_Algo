#include <stdio.h>

void swapCallByVal(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapCallByRef(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(void) {
    int valA = 2;
    int valB = 4;

    printf("Before swapCallByVal: valA = %d, valB = %d\n", valA, valB);
    swapCallByVal(valA, valB);
    printf("After swapCallByVal: valA = %d, valB = %d\n", valA, valB);

    valA = 2;
    valB = 4;

    printf("Before swapCallByRef: valA = %d, valB = %d\n", valA, valB);
    swapCallByRef(&valA, &valB);
    printf("After swapCallByRef: valA = %d, valB = %d\n", valA, valB);


    return 0;
}