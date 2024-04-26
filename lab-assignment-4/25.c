#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int priorities[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int item, int priority) {
    if (isFull()) {
        printf("Priority queue is full.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
        int i;
        for (i = rear - 1; i >= front && priority > priorities[i]; i--) {
            queue[i + 1] = queue[i];
            priorities[i + 1] = priorities[i];
        }
        rear = i + 1;
    }
    queue[rear] = item;
    priorities[rear] = priority;
}

void dequeue() {
    if (isEmpty()) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Dequeued item: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Priority queue is empty.\n");
        return;
    }
    printf("Priority queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("(%d, priority: %d) ", queue[i], priorities[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1, 2);
    enqueue(2, 1);
    enqueue(3, 3);
    enqueue(4, 2);
    enqueue(5, 4);

    display();

    dequeue();

    display();

    return 0;
}
