#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* ptr){ // checking empty or not
    if(ptr->top == -1){
        return 1; // true
    }
    else{
        return 0; // false
    }
}

int isFull(struct stack* ptr){ // checking full or not
    if(ptr->top == ptr->size-1){
        return 1; // true
    }
    else{
        return 0; // false
    } 
}

int main(){
    struct stack* s; // pointer of structure
    s->size = 6;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(s->size * sizeof(int)));

    // pushing elements

    s->arr[0] = 5;
    s->arr[1] = 6;
    s->top++;

    // checking empty
    if(isEmpty(s)){
        printf("Yes it is empty");
    }
    else{
        printf("No its not empty");
    }
}
