#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{ // structure of stack
    int size;
    int top;
    char *arr;
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

void push(struct stack* ptr, char data){
    if(isFull(ptr)){
        printf("Stack underflow\n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack overflow\n");
        return -1;
    }else{
        char data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}


int parenthesisChecker(char* exp){
    // create and initialize a stack

    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    for(int i = 0;exp[i]!='\0'; i++){
        if(exp[i] == '('){
            push(sp,'(');
        }else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if(isEmpty(sp)){
        return 1;
    }else{
        return 0;
    }
}

int main(){

char * exp = "((8)*(9))";

//check stack is empty or not
if(parenthesisChecker(exp)){
    printf("The parenthesis is Matching\n");
}
else{
    printf("The parenthesis is not Matching\n");
}

printf("%d",strlen(exp)); // length of the exp
return 0;
}
