#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;
};

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size - 1){
       return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr , int val){
    if (isFull(ptr)){ // condition for overflow
        printf("Stack overflow\n");
        printf("Cannot insert %d to the stack" ,val);
    }
    else{
        ptr->top++; // incrementation of top index 
        ptr->arr[ptr->top] = val; 
    }
}

int main(){
    struct stack* s = (struct stack*) malloc(sizeof(struct stack)); // stack pointer
    s->size = 10; // size declaration
    s->top = -1; // top index
    s->arr = (int*) malloc(s->size * sizeof(int*)); // stack creation

    printf("Stack created successfully\n");
    printf("Before pushing: %d\n",isEmpty(s));
    printf("Before Pushing: %d\n",isFull(s));

    push(s , 6);
    push(s , 13);
    push(s , 98);
    push(s , 45);
    push(s , 49);
    push(s , 57);
    push(s , 78);
    push(s , 87);
    push(s , 52);
    push(s , 23); // Stack is full
    push(s , 44); // Stack overflow as size was 10

    printf("After pushing empty: %d\n",isEmpty(s));
    printf("After pushing full:%d\n",isFull(s));
    return 0;

}
