#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int tableId, status;
    char *customerName;
} Table;

typedef struct node {
    Table data;
    struct node *next;
} Node;

void clearBuffer() {
    while (getchar() != '\n');
}

void exitProgram() {
    exit(EXIT_FAILURE);
}

Node *createNode(Table val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exitProgram();

    newNode->data.tableId = val.tableId;
    newNode->data.status = val.status;

    newNode->data.customerName = (char*)malloc(30 * sizeof(char));
    if (newNode->data.customerName == NULL) exitProgram();
    strcpy(newNode->data.customerName, val.customerName);

    newNode->next = NULL;

    return newNode;
}

void addToEnd(Node **head, Table val) {
    if (*head == NULL) {
        *head = createNode(val);
        return;
    }

    Node *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = createNode(val);
}

void inputTable(Table *t) {
    printf("Nhập mã bàn: ");
    scanf("%d", &t->tableId);
    clearBuffer();

    printf("Nhập trạng thái (1: đã đặt, 0: còn trống): ");
    scanf("%d", &t->status);
    clearBuffer();

    t->customerName = (char*)malloc(30 * sizeof(char));
    printf("Nhập tên khách: ");
    fgets(t->customerName, 30, stdin);
    t->customerName[strcspn(t->customerName, "\n")] = '\0';
}

void printTable(Table *t) {
    printf("Mã bàn: %d, Tên khách: %s, Trạng thái: %s\n", 
           t->tableId, t->customerName, t->status == 1 ? "đã đặt" : "còn trống");
}

void inputList(Node **head, int n) {
    Table val;
    for (int i = 0; i < n; i++) {
        printf("Nhập thông tin bàn thứ %d:\n", i + 1);
        inputTable(&val);
        addToEnd(head, val);
        free(val.customerName);
    }
}

void printList(Node *head) {
    while (head != NULL) {
        printTable(&head->data);
        head = head->next;
    }
}

void freeList(Node **head) {
    Node *tmp = *head;
    while (tmp != NULL) {
        Node *next = tmp->next;
        free(tmp->data.customerName);
        free(tmp);
        tmp = next;
    }
    *head = NULL;
}

int main() {
    Node *head = NULL;
    int choice, n;

    do {
        printf("1. Nhập danh sách bàn\n");
        printf("2. In danh sách bàn\n");
        printf("0. Thoát\n");
        printf("Chọn: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Nhập số lượng bàn: ");
                scanf("%d", &n);
                clearBuffer();
                inputList(&head, n);
                break;
            case 2:
                printList(head);
                break;
            case 0:
                freeList(&head);
                break;
            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 0);

    return 0;
}
