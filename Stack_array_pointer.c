#include<stdio.h>
#include<stdlib.h>

struct stack{ // structure of stack
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1; // true
    }
    else{
        return 0; // false
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

struct stack* s; // pointer of stack stucture
s->size = 10;
s->top = -1;
s->arr = (int*)malloc(s->size * sizeof(int));

//check stack is empty or not
if(isEmpty(s)){
    printf("The stack is empty");
}
else{
    printf("The stack is not empty");
}
return 0;
}