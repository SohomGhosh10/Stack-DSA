#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* ptr){ // Cheching for empty stack
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack* ptr){ // checking for full stack
    if(ptr->top == ptr->size - 1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack* ptr , int value){ // pushing element in stack
    if(isFull(ptr)){
        printf("Stack overflow\n"); // stack overflow
        return;
    }else{
        printf("%d element to be pushed is\n",value);
        ptr->top++; // increamenting top value
        ptr->arr[ptr->top] = value; // pushing elements
    }
}

void pop(struct stack * ptr, int value){ // popping elements from stack
    if(isEmpty(ptr)){ 
        printf("Stack underflow\n"); // stack underflow
        return;
    }else{
        printf("%d element to be poped out is\n",value);
        ptr->top--; // decreamenting top value 
        value = ptr->arr[ptr->top]; // popping elements
    }
}

void display(struct stack * ptr){ // displaying current stack
    printf("The current stack is\n");
    if(isEmpty(ptr)){
        printf("Stack is empty\n");
    }
    for(int i = 0; i <= ptr -> top; i++){
        printf("Element: %d\n", ptr -> arr[i]);
    }
}

int main()
{
    struct stack* sp = (struct Stack*)malloc(sizeof(struct stack)); // structure pointer
    sp -> size = 6; // size declaration
    sp -> top = -1; // top value
    sp -> arr = (int*)malloc(sp -> size * sizeof(int)); 

    // Stack operations

    pop(sp,28);
    push(sp, 28);
    push(sp, 32);
    push(sp, 52);
    push(sp, 90);
    push(sp, 25);
    push(sp, 69);
    push(sp, 17);
    pop(sp,32);
    pop(sp,17);
    display(sp); 
    return 0;
}

