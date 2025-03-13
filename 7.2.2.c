#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int maphong;
    char tenphong[30];
    int tinhtrang; // 0: còn trống, 1: đã có khách đặt
} Phong;

typedef struct node {
    Phong info;
    struct node *next;
} Node;

void init(Node **phead) {
    *phead = NULL;
}

int isEmpty(Node *phead) {
    return phead == NULL;
}

Node* createNode(Phong p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = p;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node **phead, Phong p) {
    Node *newNode = createNode(p);
    newNode->next = *phead;
    *phead = newNode;
}

void insertLast(Node **phead, Phong p) {
    Node *newNode = createNode(p);
    if (*phead == NULL) {
        *phead = newNode;
        return;
    }
    Node *current = *phead;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void inputPhong(Phong *p) {
    printf("Nhap ma phong: ");
    scanf("%d", &p->maphong);
    printf("Nhap ten phong: ");
    fflush(stdin);
    gets(p->tenphong);
    printf("Nhap tinh trang (0: con trong, 1: da co khach dat): ");
    scanf("%d", &p->tinhtrang);
}

void inputList(Node **phead) {
    int n;
    printf("Nhap so luong phong: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Phong p;
        inputPhong(&p);
        insertLast(phead, p);
    }
}

void outputPhong(Phong p) {
    printf("Ma phong: %d, Ten phong: %s, Tinh trang: %s\n", p.maphong, p.tenphong, p.tinhtrang == 0 ? "Con trong" : "Da co khach dat");
}

void outputList(Node *phead) {
    Node *current = phead;
    while (current != NULL) {
        outputPhong(current->info);
        current = current->next;
    }
}

Node* searchEmptyRoom(Node *phead) {
    Node *current = phead;
    while (current != NULL) {
        if (current->info.tinhtrang == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int countBookedRooms(Node *phead) {
    int count = 0;
    Node *current = phead;
    while (current != NULL) {
        if (current->info.tinhtrang == 1) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void sortByRoomCode(Node *phead) {
    Node *i, *j;
    Phong temp;
    for (i = phead; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info.maphong > j->info.maphong) {
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
    printf("Danh sach phong:\n");
    outputList(head);

    Node *emptyRoom = searchEmptyRoom(head);
    if (emptyRoom == NULL) {
        printf("Khong co phong nao con trong.\n");
    } else {
        printf("Phong dau tien con trong:\n");
        outputPhong(emptyRoom->info);
    }

    printf("So luong phong da co khach dat: %d\n", countBookedRooms(head));

    Phong newRoom;
    printf("Nhap thong tin phong moi:\n");
    inputPhong(&newRoom);
    insertLast(&head, newRoom);
    printf("Danh sach phong sau khi them phong moi:\n");
    outputList(head);

    sortByRoomCode(head);
    printf("Danh sach phong sau khi sap xep theo ma phong:\n");
    outputList(head);

    return 0;
}
