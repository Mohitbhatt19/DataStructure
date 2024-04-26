#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full.\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = item;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    display();

    dequeue();

    display();

    return 0;
}
