#include <stdio.h>

#define MAX_SIZE 5

int deque[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return ((rear + 1) % MAX_SIZE == front || (front == 0 && rear == MAX_SIZE - 1));
}

void insertFront(int item) {
    if (isFull()) {
        printf("Deque is full.\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    deque[front] = item;
}

void insertRear(int item) {
    if (isFull()) {
        printf("Deque is full.\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    do {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    insertFront(1);
    insertRear(2);
    insertRear(3);
    insertFront(4);
    
    display();
    
    deleteFront();
    
    display();
    
    deleteRear();
    
    display();
    
    return 0;
}
