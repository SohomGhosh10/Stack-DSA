#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * next;
    int data;
};

void linkedListTraversal(struct Node* ptr){ // For traversal of full stack
    while(ptr!=NULL){
        printf("Elements are %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top){
    if(top == NULL){ // if top is pointing to NULL
        return 1; // True
    }else{
        return 0; // False
    }
}

int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){ // if stack is full, no memory allocation is possible
        return 1; // True
    }else{
        return 0; // False
    }
}

struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack overflow\n");
    }else{
        struct Node* n = (struct Node*)malloc(sizeof(struct Node)); // Creating node
        n->data = x;
        // Linking node
        
        n->next = top; 
        top = n;
        return top;
    }
}

int main(){
    struct Node * top = NULL;
    top = push(top,56);
    top = push(top,78);
    top = push(top,98);
    linkedListTraversal(top); // Printing new stack
    return 0;
}
