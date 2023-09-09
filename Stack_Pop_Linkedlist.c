#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * next;
    int data;
};

void linkedListTraversal(struct Node* ptr){ // Traversal od the stack
    while(ptr!=NULL){
        printf("Elements are %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node)); // Node allocation
    if(p == NULL){ // if memory is full, pushing is not allowed
        return 1;
    }else{
        return 0;
    }
}

struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack overflow\n");
    }else{
        // Node creation
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x; // Storing data
        n->next = top; // Linking
        top = n;
        return top;
    }
}

int pop(struct Node** top){ // pointer to pointer type
     if(isEmpty(*top)){
        printf("Stack underflow\n");
    }else{
        struct Node* n = *top;
        *top = (*top)->next; // at first dereferencing then traverse it's next
        int x = n->data; // storing data
        free(n); // deleting the previous node
        return x;
    }
}

int main(){
    struct Node * top = NULL;
    // Push operations
    top = push(top,56);
    top = push(top,78);
    top = push(top,98);
    int element = pop(&top); // sending the address of top
    printf("Popped element is %d\n",element); // Popped elements
    linkedListTraversal(top); // Stack display
    return 0;
}
