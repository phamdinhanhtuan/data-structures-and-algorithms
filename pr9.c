#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char mahang[10];
    char tenhang[30];
    int soluong;
} MH;

typedef struct node {
    MH info;
    struct node *next;
} Node;

void init(Node **phead) {
    *phead = NULL;
}

int isEmpty(Node *phead) {
    return phead == NULL;
}

Node* createNode(MH m) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = m;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node **phead, MH m) {
    Node *newNode = createNode(m);
    newNode->next = *phead;
    *phead = newNode;
}

void inputMH(MH *m) {
    printf("Nhap ma hang: ");
    fflush(stdin);
    gets(m->mahang);
    printf("Nhap ten hang: ");
    fflush(stdin);
    gets(m->tenhang);
    printf("Nhap so luong: ");
    scanf("%d", &m->soluong);
}

void inputList(Node **phead) {
    int n;
    printf("Nhap so luong mat hang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        MH m;
        inputMH(&m);
        insertFirst(phead, m);
    }
}

void outputMH(MH m) {
    printf("Ma hang: %s, Ten hang: %s, So luong: %d\n", m.mahang, m.tenhang, m.soluong);
}

void outputList(Node *phead) {
    Node *current = phead;
    while (current != NULL) {
        outputMH(current->info);
        current = current->next;
    }
}

Node* search(Node *phead, char x[]) {
    Node *current = phead;
    while (current != NULL) {
        if (strcmp(current->info.mahang, x) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertAfter(Node *p, MH m) {
    Node *newNode = createNode(m);
    newNode->next = p->next;
    p->next = newNode;
}

void deleteFirst(Node **phead) {
    if (*phead == NULL) return;
    Node *temp = *phead;
    *phead = (*phead)->next;
    free(temp);
}

void deleteAll(Node **phead) {
    Node *current = *phead;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *phead = NULL;
}

void deleteElement(Node **phead, char x[]) {
    Node *current = *phead;
    Node *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->info.mahang, x) == 0) {
            if (prev == NULL) {
                *phead = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void sort(Node *phead) {
    Node *i, *j;
    MH temp;
    for (i = phead; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->info.tenhang, j->info.tenhang) > 0) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

int main() {
    Node *head;
    init(&head);

    inputList(&head);
    printf("Danh sach mat hang:\n");
    outputList(head);

    char x[10];
    printf("Nhap ma hang can tim: ");
    fflush(stdin);
    gets(x);
    Node *kg = search(head, x);
    if (kg == NULL) {
        printf("Khong tim thay mat hang.\n");
    } else {
        printf("Mat hang tim duoc:\n");
        outputMH(kg->info);
    }

    printf("Nhap ma hang can tim de them mat hang sau no: ");
    fflush(stdin);
    gets(x);
    kg = search(head, x);
    if (kg == NULL) {
        printf("Khong tim thay mat hang.\n");
    } else {
        MH m;
        inputMH(&m);
        insertAfter(kg, m);
        printf("Danh sach sau khi them:\n");
        outputList(head);
    }

    deleteFirst(&head);
    printf("Danh sach sau khi xoa mat hang dau:\n");
    outputList(head);

    printf("Nhap ma hang can xoa: ");
    fflush(stdin);
    gets(x);
    deleteElement(&head, x);
    printf("Danh sach sau khi xoa mat hang co ma %s:\n", x);
    outputList(head);

    sort(head);
    printf("Danh sach sau khi sap xep theo ten hang:\n");
    outputList(head);

    deleteAll(&head);
    printf("Danh sach sau khi xoa toan bo:\n");
    outputList(head);

    return 0;
}
