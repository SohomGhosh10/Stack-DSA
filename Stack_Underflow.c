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
    if (isEmpty(ptr)){
        printf("\nStack underflow\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    struct stack* s = (struct stack*) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*) malloc(s->size * sizeof(int*));

    printf("Stack created successfully\n");
    printf("Before pushing: %d\n",isEmpty(s));
    printf("Before Pushing: %d\n",isFull(s));

    push(s , 56);
    push(s , 56);
    push(s , 56);
    push(s , 56);
    push(s , 56);
    push(s , 56);
    push(s , 56);
    push(s , 56);
    push(s , 56);
    push(s , 56);
    push(s , 57);

    printf("\nThe %d element is removed from the stack\n",pop(s));

    printf("After pushing empty: %d\n",isEmpty(s));
    printf("After pushing full:%d\n",isFull(s));
    return 0;

}