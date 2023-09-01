#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack* ptr , int value){
    if(isFull(ptr)){
        printf("Stack overflow\n");
        return;
    }else{
        printf("%d element to be pushed is\n",value);
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

void pop(struct stack * ptr, int value){
    if(isEmpty(ptr)){
        printf("Stack underflow\n");
        return;
    }else{
        printf("%d element to be poped out is\n",value);
        ptr->top--;
        value = ptr->arr[ptr->top];
    }
}

void display(struct stack * ptr){
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
    struct stack* sp = (struct Stack*)malloc(sizeof(struct stack));
    sp -> size = 6;
    sp -> top = -1;
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

