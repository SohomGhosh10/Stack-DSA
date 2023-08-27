#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack * ptr){ // struct stack type pointer
    if(ptr->top == -1){ // checking for empty
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size - 1){ // checking for full
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack)); // struct stack * s stores the address of the whole structure
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack created successfully\n");
    printf("%d\n",isEmpty(s)); // 1
    printf("%d\n",isFull(s)); // 0

    return 0;
}
