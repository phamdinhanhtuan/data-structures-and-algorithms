#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MatHang {
    char maHang[10];
    char tenHang[50];
    int soLuong;
    struct MatHang* next;
};

typedef struct MatHang* LinkedList;

int isEmpty(LinkedList list) {
    return (list == NULL);
}

int demSoNode(LinkedList list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

void giaiPhongDanhSach(LinkedList* list) {
    struct MatHang* current = *list;
    struct MatHang* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}

struct MatHang* taoNode(char* ma, char* ten, int sl) {
    struct MatHang* node = (struct MatHang*)malloc(sizeof(struct MatHang));
    strcpy(node->maHang, ma);
    strcpy(node->tenHang, ten);
    node->soLuong = sl;
    node->next = NULL;
    return node;
}

void nhapDanhSach(LinkedList* list) {
    char ma[10], ten[50];
    int sl;
    char tiepTuc;
    do {
        printf("\nNhap ma hang: ");
        scanf("%s", ma);
        printf("Nhap ten hang: ");
        scanf(" %[^\n]s", ten);
        printf("Nhap so luong: ");
        scanf("%d", &sl);
        struct MatHang* newNode = taoNode(ma, ten, sl);
        newNode->next = *list;
        *list = newNode;
        printf("Tiep tuc nhap? (y/n): ");
        scanf(" %c", &tiepTuc);
    } while (tiepTuc == 'y' || tiepTuc == 'Y');
}

void xuatDanhSach(LinkedList list) {
    printf("\nDanh sach mat hang:\n");
    printf("%-10s %-30s %-10s\n", "Ma hang", "Ten hang", "So luong");
    printf("----------------------------------------\n");
    while (list != NULL) {
        printf("%-10s %-30s %-10d\n", list->maHang, list->tenHang, list->soLuong);
        list = list->next;
    }
}

struct MatHang* timMatHang(LinkedList list, char* maX) {
    while (list != NULL) {
        if (strcmp(list->maHang, maX) == 0) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

void themSauMaX(LinkedList* list, char* maX, char* ma, char* ten, int sl) {
    struct MatHang* p = *list;
    while (p != NULL) {
        if (strcmp(p->maHang, maX) == 0) {
            struct MatHang* newNode = taoNode(ma, ten, sl);
            newNode->next = p->next;
            p->next = newNode;
            return;
        }
        p = p->next;
    }
    printf("Khong tim thay mat hang co ma %s\n", maX);
}

void xoaDau(LinkedList* list) {
    if (*list != NULL) {
        struct MatHang* temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

void xoaDanhSach(LinkedList* list) {
    while (*list != NULL) {
        xoaDau(list);
    }
}

void xoaMatHang(LinkedList* list, char* maX) {
    if (*list == NULL) return;
    if (strcmp((*list)->maHang, maX) == 0) {
        xoaDau(list);
        return;
    }
    struct MatHang* p = *list;
    while (p->next != NULL) {
        if (strcmp(p->next->maHang, maX) == 0) {
            struct MatHang* temp = p->next;
            p->next = p->next->next;
            free(temp);
            return;
        }
        p = p->next;
    }
}

void sapXepTheoTen(LinkedList* list) {
    if (*list == NULL || (*list)->next == NULL) return;
    struct MatHang* i, *j;
    char tempMa[10], tempTen[50];
    int tempSL;
    for (i = *list; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->tenHang, j->tenHang) > 0) {
                strcpy(tempMa, i->maHang);
                strcpy(tempTen, i->tenHang);
                tempSL = i->soLuong;
                strcpy(i->maHang, j->maHang);
                strcpy(i->tenHang, j->tenHang);
                i->soLuong = j->soLuong;
                strcpy(j->maHang, tempMa);
                strcpy(j->tenHang, tempTen);
                j->soLuong = tempSL;
            }
        }
    }
}

int main() {
    LinkedList list = NULL;
    int choice;
    char maX[10], ma[10], ten[50];
    int sl;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap danh sach mat hang\n");
        printf("2. Xuat danh sach mat hang\n");
        printf("3. Tim mat hang theo ma\n");
        printf("4. Them mat hang sau ma X\n");
        printf("5. Xoa mat hang dau\n");
        printf("6. Xoa toan bo danh sach\n");
        printf("7. Xoa mat hang co ma X\n");
        printf("8. Sap xep theo ten hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                nhapDanhSach(&list);
                break;
            case 2:
                xuatDanhSach(list);
                break;
            case 3:
                printf("Nhap ma can tim: ");
                scanf("%s", maX);
                struct MatHang* kq = timMatHang(list, maX);
                if (kq != NULL) {
                    printf("Tim thay mat hang: %s - %s - %d\n", kq->maHang, kq->tenHang, kq->soLuong);
                } else {
                    printf("Khong tim thay mat hang!\n");
                }
                break;
            case 4:
                printf("Nhap ma X: ");
                scanf("%s", maX);
                printf("Nhap thong tin mat hang moi:\n");
                printf("Ma hang: ");
                scanf("%s", ma);
                printf("Ten hang: ");
                scanf(" %[^\n]s", ten);
                printf("So luong: ");
                scanf("%d", &sl);
                themSauMaX(&list, maX, ma, ten, sl);
                break;
            case 5:
                xoaDau(&list);
                printf("Da xoa mat hang dau danh sach!\n");
                break;
            case 6:
                xoaDanhSach(&list);
                printf("Da xoa toan bo danh sach!\n");
                break;
            case 7:
                printf("Nhap ma can xoa: ");
                scanf("%s", maX);
                xoaMatHang(&list, maX);
                break;
            case 8:
                sapXepTheoTen(&list);
                printf("Da sap xep danh sach theo ten!\n");
                break;
        }
    } while (choice != 0);
    xoaDanhSach(&list);
    return 0;
}
