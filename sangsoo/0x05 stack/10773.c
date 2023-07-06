#include <stdio.h>
#include <stdlib.h>

int main(){
    int K, input;
    scanf("%d", &K);

    int *intarr = (int *)malloc(K*sizeof(int));
    for (int i = 0; i < K; i++){
        scanf("%d", &intarr[i]);
    }
    int *stack = (int *)malloc(K * sizeof(int));
    int stackTop = 0;

    for (int i = 0; i < K; i++){
        if (intarr[i] != 0){
            stack[stackTop++] = intarr[i];
        }
        else{
            stackTop--;
        }
    }
    int sum = 0;
    for (int i = 0; i < stackTop; i++){
        sum += stack[i];
    }
    printf("%d\n", sum);
    
    free(intarr);
    free(stack);
    
    return 0;
}