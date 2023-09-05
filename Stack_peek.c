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
    if(ptr->top == ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack* ptr, int data){
    if(isFull(ptr)){
        printf("Stack underflow\n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack overflow\n");
        return -1;
    }else{
        int data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}

int peek(struct stack* sp, int i){
    int Index = sp->top - i + 1;
    if(Index < 0){ // invalid
        printf("Invalid index\n");
        return -1;
    }else{
        return sp->arr[Index]; // returns index of elements
    }
}

int main(){
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size * sizeof(int));

    //Before pushing and poping
    printf("Before pushing, Full is %d\n",isFull(sp));
    printf("Before poping, Empty is %d\n",isEmpty(sp));

    //Pushing elements
    
    push(sp,1);
    push(sp,23);
    push(sp,99);
    push(sp,75);
    push(sp,3);
    push(sp,64);
    push(sp,57);
    push(sp,49);
    push(sp,89);
    push(sp,6);

    printf("After pushing, Full is %d\n",isFull(sp));
    printf("After poping, Empty is %d\n",isEmpty(sp));

    printf("Popped %d from the stack\n",pop(sp)); // Last in first out
    printf("Popped %d from the stack\n",pop(sp)); // Last in first out
    printf("Popped %d from the stack\n",pop(sp)); // Last in first out

    // Printing the values from the stack
    
    for(int j = 1; j <= sp->top + 1; j++){
        printf("The value at index %d is %d\n",j ,peek(sp,j));
    }

    return 0;
}
