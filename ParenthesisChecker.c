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

void push(struct stack* ptr, char data){ // character type data
    if(isFull(ptr)){
        printf("Stack overflow\n"); // Overflow condition 
    }else{
        ptr->top++; // incrementing top
        ptr->arr[ptr->top] = data; // pushing data
    }
}

char pop(struct stack* ptr){ // popping a character
    if(isEmpty(ptr)){
        printf("Stack underflow\n"); // underflow condition
        return -1;
    }else{
        char data = ptr->arr[ptr->top]; // popping character
        ptr->top--; // decrementing top
        return data;
    }
}


int parenthesisChecker(char* exp){ // character type pointer
    // create and initialize a stack

    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    for(int i = 0;exp[i]!='\0'; i++){
        if(exp[i] == '('){ 
            push(sp,'('); // for ( bracket, push in stack
        }else if(exp[i] == ')'){ // for ) bracket, pop all elements upto ( bracket is found
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp); // pop elements
        }
    }

    if(isEmpty(sp)){
        return 1;
    }else{
        return 0;
    }
}

int main(){

char * exp = "((8)*(9))"; // character type expression

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
