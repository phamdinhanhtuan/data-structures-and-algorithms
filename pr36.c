#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Khai báo cấu trúc Queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Khởi tạo queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Kiểm tra queue rỗng
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Thêm phần tử vào cuối queue (enqueue)
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Lấy phần tử từ đầu queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    // Nếu queue trở thành rỗng sau khi dequeue
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

// Lấy giá trị phần tử đầu queue (peek)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// In ra các phần tử trong queue
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Giải phóng bộ nhớ
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Hàm main để test
int main() {
    Queue* q = createQueue();

    // Thêm các phần tử vào queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // In queue
    printQueue(q);

    // Lấy phần tử từ queue
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    // In queue sau khi dequeue
    printQueue(q);

    // Lấy giá trị phần tử đầu queue
    printf("Front element: %d\n", peek(q));

    // Giải phóng bộ nhớ
    freeQueue(q);

    return 0;
}
