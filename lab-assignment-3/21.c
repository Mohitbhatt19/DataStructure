#include <stdio.h>
#define SIZE 5

int front = -1, rear = -1;
int queue[SIZE];

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
    printf("Element %d \n", value);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty. No elements to display.\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    return 0;
}
