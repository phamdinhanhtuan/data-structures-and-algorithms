#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize a queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    // Example usage
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    display(&q);
    
    dequeue(&q);
    display(&q);
    
    enqueue(&q, 40);
    display(&q);

    return 0;
}
