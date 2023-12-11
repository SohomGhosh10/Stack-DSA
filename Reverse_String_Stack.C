#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to reverse a string using two stacks
void reverseStringWithTwoStacks(char str[]) {
    // Create two stacks
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    // Push each character onto the first stack
    for (int i = 0; i < strlen(str); i++) {
        push(&stack1, str[i]);
    }

    // Pop each character from the first stack and push onto the second stack
    while (!isEmpty(&stack1)) {
        char item = pop(&stack1);
        push(&stack2, item);
    }

    // Pop each character from the second stack to reverse the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack2);
    }
}

int main() {
    char str[100];

    // Input a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string using two stacks
    reverseStringWithTwoStacks(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
