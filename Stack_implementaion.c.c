#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int* arr;
};
int isEmpty(struct Stack* ptr) // Stack is empty or not
{
    if (ptr -> top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct Stack* ptr) // Stack is Full or not.
{
    if (ptr -> top == ptr -> size - 1){
        return 1;
    }
    return 0;
}

// For pushing elements in stack

void push(struct Stack* ptr, int value) 
{
    if (isFull(ptr)) // Stack overflow
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("%d is pushing inside the stack...\n", value);
    ptr -> top++;
    ptr -> arr[ptr -> top] = value;
}

// For poping element from stack

void pop(struct Stack* ptr)
{
    if (isEmpty(ptr)) // Underflow condition
    {
        printf("Stack Underflow\n");
        return;
    }
    int val = ptr -> arr[ptr -> top];
    ptr -> top--;
    printf("%d Popped Out From The Stack.\n", val);
}

// For displaying the current stack

void display(struct Stack* ptr) 
{
    if (isEmpty(ptr)){
        printf("Stack is Empty\n");
    }
    for(int i = 0; i <= ptr -> top; i++){
        printf("Element: %d\n", ptr -> arr[i]);
    }
}

// Peeking the elements from top.

int peek(struct Stack* ptr, int position) 
{
    if ((ptr -> top - position + 1) < 0)
    {
        printf("Not valid index\n");
        return -1;
    }
    return ptr -> arr[ptr -> top - position + 1];
}
int main()
{
    struct Stack* sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp -> size = 6;
    sp -> top = -1;
    sp -> arr = (int*)malloc(sp -> size * sizeof(int));

    // Stack operations

    pop(sp);
    push(sp, 28);
    push(sp, 32);
    push(sp, 52);
    push(sp, 90);
    push(sp, 25);
    push(sp, 69);
    push(sp, 17);
    pop(sp);
    pop(sp);
    display(sp);
    printf("%d",peek(sp, 2));
    return 0;
}