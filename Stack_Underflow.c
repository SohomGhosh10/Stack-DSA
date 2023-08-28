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
    if (isFull(ptr)){
        printf("Stack overflow\n");
        printf("Cannot insert %d to the stack" ,val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack * ptr){
    if (isEmpty(ptr)){ // checking for underflow
        printf("\nStack underflow\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top]; // condition for underflow
        ptr->top--; // decrementation of top index
        return val;
    }
}

int main(){
    struct stack* s = (struct stack*) malloc(sizeof(struct stack)); // stack pointer
    s->size = 10; // size declaration
    s->top = -1; // top index
    s->arr = (int*) malloc(s->size * sizeof(int*)); // array creation

    printf("Stack created successfully\n");
    printf("Before pushing: %d\n",isEmpty(s));
    printf("Before Pushing: %d\n",isFull(s));

    push(s , 6);
    push(s , 16);
    push(s , 30);
    push(s , 45);
    push(s , 49);
    push(s , 87);
    push(s , 33);
    push(s , 23);
    push(s , 98);
    push(s , 78); // pushed 10 elements
    push(s , 56); // cannot push another element as size is 10

    printf("\nThe %d element is removed from the stack\n",pop(s)); // poped last element from the stack

    printf("After pushing empty: %d\n",isEmpty(s));
    printf("After pushing full:%d\n",isFull(s));
    return 0;

}
