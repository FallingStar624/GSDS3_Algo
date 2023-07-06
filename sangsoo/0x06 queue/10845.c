#include <stdio.h>
#include <string.h>
int queue[10845];
int queue_size = 0;

void push(int push_data){
    queue[queue_size++] = push_data;
}

int empty(){
    if(queue_size == 0){
        return 1;
    }
    return 0;
}

int pop(){
    if(empty()){
        return -1;
    }
    queue_size -= 1;
    int out = queue[0];
    for (int i = 0; i < queue_size; i++){
        queue[i] = queue[i+1]; 
    }
    return out;
}

int front(){
    if(empty()){
        return -1;
    }
    return queue[0];
}

int back(){
    if(empty()){
        return -1;
    }
    return queue[queue_size - 1];
}


int main(){
    int N = 0, push_data = 0;
    char command[5] = {0, };

    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%s", command);
        if(!strcmp(command, "push")){
            scanf("%d", &push_data);
            push(push_data);
        }
        else if(!strcmp(command, "pop")){
            printf("%d\n", pop());
        }
        else if(!strcmp(command, "empty")){
            printf("%d\n", empty());
        }
        else if(!strcmp(command,"size")){
            printf("%d\n", queue_size);
        }
        else if(!strcmp(command,"front")){
            printf("%d\n", front());
        }
        else if(!strcmp(command, "back")){
            printf("%d\n", back());
        }
    }
    return 0;
}