#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("Element %d \n", value);
}

void display() {
    if (top == -1) {
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
    push(40);

    display();

    return 0;
}
