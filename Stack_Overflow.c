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
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
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

    printf("After pushing empty: %d\n",isEmpty(s));
    printf("After pushing full:%d\n",isFull(s));
    return 0;

}