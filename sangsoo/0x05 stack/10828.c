#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_COMMAND 100
#define MAX_SIZE 10000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value){
    stack->data[++stack->top] = value; // same with stack->top = stack->top + 1
}

int pop(Stack *stack){
    return stack -> top < 0 ? -1 : stack->data[stack->top--]; // condition ? expression_if_true : expression_if_false.
}

int size(Stack *stack){
    return stack->top + 1;
}

int empty(Stack *stack){
    return stack->top < 0 ? 1 : 0;
}

int top(Stack *stack){
    return stack -> top < 0 ? -1 : stack->data[stack->top];
}

int main(){
    int n;
    scanf("%d", &n);

    Stack stack;
    stack.top = -1;
    for (int i = 0; i < n; i++){
        char command[MAX_COMMAND];
        scanf("%s", command);
        
        if (strcmp(command, "push") == 0){
            int value;
            scanf("%d", &value);
            push(&stack, value);
        }
        else if (strcmp(command, "pop") == 0){
            printf("%d\n", pop(&stack));
        }
        else if (strcmp(command, "size") == 0){
            printf("%d\n", size(&stack));
        }
        else if (strcmp(command, "empty") == 0){
            printf("%d\n", empty(&stack));
        }
        else if (strcmp(command, "top") == 0){
            printf("%d\n", top(&stack));
        }
    }
    return 0;
}