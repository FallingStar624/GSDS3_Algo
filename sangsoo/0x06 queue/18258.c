#include <stdio.h>
#include <string.h>
int queue[2000001];
int head = 0;
int tail = 0;

void push(int push_data){
    queue[tail++] = push_data;
}

int empty(){
    return head == tail;
}

int pop(){
    if(empty()){
        return -1;
    }
    return queue[head++];
}

int front(){
    if(empty()){
        return -1;
    }
    return queue[head];
}

int back(){
    if(empty()){
        return -1;
    }
    return queue[tail - 1];
}
int size(){
    return tail-head;
}


int main(){
    int N = 0, push_data = 0;
    char command[10];

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
            printf("%d\n", size());
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