#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full.\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
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
        front = (front + 1) % MAX_SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    dequeue();

    display();

    enqueue(6);

    display();

    return 0;
}
