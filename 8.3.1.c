#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct benhnhan {
    int stt;
    char hoten[30];
    int tuoi;
} BenhNhan;

typedef struct node {
    BenhNhan info;
    struct node *next;
} Node;

typedef struct QUEUE {
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, BenhNhan bn) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = bn;
    newNode->next = NULL;
    if (q->tail == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}

BenhNhan dequeue(Queue *q) {
    if (q->head == NULL) {
        BenhNhan empty = {0, "", 0};
        return empty;
    }
    Node *temp = q->head;
    BenhNhan bn = temp->info;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    q->size--;
    return bn;
}

int daKham(Queue *q) {
    return q->size;
}

int chuaKham(Queue *q) {
    return q->size;
}

void printQueue(Queue *q) {
    Node *temp = q->head;
    while (temp != NULL) {
        printf("STT: %d, Ho ten: %s, Tuoi: %d\n", temp->info.stt, temp->info.hoten, temp->info.tuoi);
        temp = temp->next;
    }
}

int main() {
    Queue *q = createQueue();
    int choice, stt = 1;
    BenhNhan bn;

    while (1) {
        printf("\n1. Them benh nhan\n2. Lay benh nhan tiep theo\n3. So luong da kham\n4. So luong chua kham\n5. Danh sach benh nhan cho kham\n6. Thoat\nChon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bn.stt = stt++;
                printf("Nhap ho ten: ");
                scanf("%s", bn.hoten);
                printf("Nhap tuoi: ");
                scanf("%d", &bn.tuoi);
                enqueue(q, bn);
                break;
            case 2:
                bn = dequeue(q);
                if (bn.stt == 0) {
                    printf("Khong co benh nhan nao trong hang doi.\n");
                } else {
                    printf("Benh nhan tiep theo: STT: %d, Ho ten: %s, Tuoi: %d\n", bn.stt, bn.hoten, bn.tuoi);
                }
                break;
            case 3:
                printf("So luong da kham: %d\n", stt - 1 - daKham(q));
                break;
            case 4:
                printf("So luong chua kham: %d\n", chuaKham(q));
                break;
            case 5:
                printQueue(q);
                break;
            case 6:
                exit(0);
            default:
                printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}
