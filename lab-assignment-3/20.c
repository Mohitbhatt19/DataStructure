#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int element) {
    if (isFull()) {
        printf("Stack overflow! Cannot insert element.\n");
        return;
    }
    stack[++top] = element;
    printf("Element %d inserted into the stack.\n", element);
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow! No element to delete.\n");
        return -1; 
    }
    return stack[top--];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty. No elements to display.\n");
        return;
    }
    printf("Elements in the stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Stack before deletion:\n ");
    display();

    int deletedElement = pop();
    if (deletedElement != -1) {
        printf("Deleted element: %d\n", deletedElement);
    }

    printf("Stack after deletion:\n ");
    display();

    return 0;
}
