#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int orderId;
    float totalAmount;
} Order;

typedef struct Node {
    Order data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Order val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

Order dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng!\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = q->front;
    Order order = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return order;
}

void inputOrder(Order *o) {
    printf("Nhập mã đơn hàng: ");
    scanf("%d", &o->orderId);
    printf("Nhập tổng thành tiền: ");
    scanf("%f", &o->totalAmount);
}

void printOrder(Order *o) {
    printf("Mã đơn hàng: %d, Tổng thành tiền: %.2f\n", o->orderId, o->totalAmount);
}

void printQueue(Queue *q) {
    Node *current = q->front;
    while (current != NULL) {
        printOrder(&current->data);
        current = current->next;
    }
}

int main() {
    Queue q;
    initQueue(&q);
    int choice;
    Order order;

    do {
        printf("1. Nhập danh sách đơn hàng\n");
        printf("2. Xuất danh sách đơn hàng\n");
        printf("3. Thêm một đơn hàng vào danh sách\n");
        printf("4. Lấy 1 đơn hàng ra khỏi danh sách\n");
        printf("0. Thoát\n");
        printf("Chọn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập đơn hàng:\n");
                inputOrder(&order);
                enqueue(&q, order);
                break;
            case 2:
                printf("Danh sách đơn hàng:\n");
                printQueue(&q);
                break;
            case 3:
                printf("Nhập đơn hàng:\n");
                inputOrder(&order);
                enqueue(&q, order);
                break;
            case 4:
                if (!isEmpty(&q)) {
                    printf("Đơn hàng đã lấy ra:\n");
                    printOrder(&dequeue(&q));
                } else {
                    printf("Không có đơn hàng nào để lấy ra!\n");
                }
                break;
            case 0:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 0);

    return 0;
}
