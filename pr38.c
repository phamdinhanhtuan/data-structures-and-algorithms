#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_QUEUE 100

typedef struct {
    int id;
    char name[MAX_NAME];
    int age;
} Patient;

typedef struct {
    Patient data[MAX_QUEUE];
    int front;
    int rear;
    int examined;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->examined = 0;
}

int isFull(Queue *q) {
    return q->rear == MAX_QUEUE - 1;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

void addPatient(Queue *q) {
    if (isFull(q)) {
        printf("Hang doi da day!\n");
        return;
    }

    Patient p;
    p.id = q->rear + 2;
    
    printf("Nhap ho ten: ");
    scanf(" %[^\n]s", p.name);
    
    printf("Nhap tuoi: ");
    scanf("%d", &p.age);
    
    q->rear++;
    q->data[q->rear] = p;
    printf("Da them benh nhan vao hang doi.\n");
}

void examineNextPatient(Queue *q) {
    if (isEmpty(q)) {
        printf("Khong con benh nhan cho kham!\n");
        return;
    }

    Patient p = q->data[q->front];
    printf("\nThong tin benh nhan dang kham:\n");
    printf("So thu tu: %d\n", p.id);
    printf("Ho ten: %s\n", p.name);
    printf("Tuoi: %d\n", p.age);
    
    q->front++;
    q->examined++;
}

void displayWaitingCount(Queue *q) {
    int waiting = q->rear - q->front + 1;
    if (waiting < 0) waiting = 0;
    printf("So luong nguoi chua kham: %d\n", waiting);
}

void displayExaminedCount(Queue *q) {
    printf("So luong nguoi da kham: %d\n", q->examined);
}

void displayWaitingList(Queue *q) {
    if (isEmpty(q)) {
        printf("Khong co benh nhan trong hang doi!\n");
        return;
    }

    printf("\nDanh sach benh nhan cho kham:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("STT: %d | Ho ten: %s | Tuoi: %d\n", 
               q->data[i].id, q->data[i].name, q->data[i].age);
    }
}

int main() {
    Queue queue;
    initQueue(&queue);
    int choice;

    do {
        printf("\n=== QUAN LY HANG DOI KHAM BENH ===\n");
        printf("1. Them benh nhan moi\n");
        printf("2. Kham benh nhan tiep theo\n");
        printf("3. Xem so luong nguoi da kham\n");
        printf("4. Xem so luong nguoi chua kham\n");
        printf("5. Xem danh sach cho\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(&queue); break;
            case 2: examineNextPatient(&queue); break;
            case 3: displayExaminedCount(&queue); break;
            case 4: displayWaitingCount(&queue); break;
            case 5: displayWaitingList(&queue); break;
            case 0: printf("Tam biet!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}
