#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int maPhong, tinhTrang;
    char *tenPhong;
} phong;

typedef struct node {
    phong data;
    struct node *next;
} node;

void xoaBoDem() {
    while (getchar() != '\n');
}

void lexit() {
    exit(EXIT_FAILURE);
}

void nhapMotPhong(phong *p) {
    while (1) {
        printf("Nhap ma phong: ");
        if (scanf("%d", &p->maPhong) == 1 && p->maPhong >= 0) {
            break;
        }
        printf("Vui long nhap ma phong hop le!\n");
        xoaBoDem();
    }
    xoaBoDem();

    while (1) {
        printf("Nhap tinh trang (1: da dat, 0: con trong): ");
        if (scanf("%d", &p->tinhTrang) == 1 && (p->tinhTrang == 0 || p->tinhTrang == 1)) {
            break;
        }
        printf("Vui long nhap tinh trang hop le (0 hoac 1)!\n");
        xoaBoDem();
    }
    xoaBoDem();

    printf("Nhap ten phong: ");
    p->tenPhong = (char*)malloc(30 * sizeof(char));
    if (p->tenPhong == NULL) lexit();
    fgets(p->tenPhong, 30, stdin);
    p->tenPhong[strcspn(p->tenPhong, "\n")] = '\0';
}

void xuatMotPhong(phong *p) {
    printf("Ma phong: %d\n", p->maPhong);
    printf("Tinh trang: %d\n", p->tinhTrang);
    printf("Ten phong: %s\n", p->tenPhong);
}

node *taoNode(phong val) {
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) lexit();

    newNode->data.maPhong = val.maPhong;
    newNode->data.tinhTrang = val.tinhTrang;

    newNode->data.tenPhong = (char*)malloc(30 * sizeof(char));
    if (newNode->data.tenPhong == NULL) lexit();
    strcpy(newNode->data.tenPhong, val.tenPhong); 

    newNode->next = NULL;

    return newNode;
}

node* themSau(node **head, phong val) {
    if (*head == NULL) {
        *head = taoNode(val);
        return *head;
    }

    node *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = taoNode(val);

    return tmp->next;
}

void nhapSoLuongPhong(int *n) {
    while (1) {
        printf("Nhap so luong phong: ");
        if (scanf("%d", n) == 1 && *n >= 0) {
            break;
        }
        printf("Vui long nhap so luong hop le!\n");
        xoaBoDem();
    }
}

void nhapDanhSachPhong(node **head, int n) {
    phong val;
    for (int i = 0; i < n; i++) {
        printf("Nhap phong thu %d:\n", i + 1);
        nhapMotPhong(&val);
        themSau(head, val);
        free(val.tenPhong); 
    }
}

void xuatDanhSachPhong(node *head) {
    if (head == NULL) {
        printf("Danh sach phong rong!\n");
        return;
    }

    while (head != NULL) {
        xuatMotPhong(&head->data);
        head = head->next;
    }
}

node* timPhongDauTienConTrong(node *head) {
    while (head != NULL) {
        if (head->data.tinhTrang == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int demSoLuongPhongDaDat(node *head) {
    int cnt = 0;
    while (head != NULL) {
        if (head->data.tinhTrang == 1) {
            cnt++;
        }
        head = head->next;
    }
    return cnt;
}

node* themPhongMoiVaoCuoiDanhSach(node **head, phong val) {
    return themSau(head, val);
}

node* timPhongCoMaCoMaX(node *head, int x) {
    while (head != NULL) {
        if (head->data.maPhong == x) {
            return head;
        }
        head = head->next;
    }
    
    return NULL;
}

node* themMotPhongVaoSauPhongCoMaX(node **head, int x) {
    phong val;
    nhapMotPhong(&val);

    node *tmp = *head;
    while (tmp != NULL) {
        if (tmp->data.maPhong == x) {
            node *newNode = taoNode(val);
            newNode->next = tmp->next;
            tmp->next = newNode;
            free(val.tenPhong);
            return newNode;
        }
        tmp = tmp->next;
    }

    printf("Khong tim thay phong co ma %d!\n", x);
    free(val.tenPhong);

    return NULL;
}

node* xoaPhongDauTien(node **head) {
    if (*head == NULL) return NULL;

    node *tmp = *head;
    *head = tmp->next;
    free(tmp->data.tenPhong);
    free(tmp);

    return *head;
}

void xoaToanBoPhong(node **head) {
    while (*head != NULL) {
        node *tmp = *head;
        *head = tmp->next;
        free(tmp->data.tenPhong);
        free(tmp);
    }
}

void swap(phong *a, phong *b) {
    int tmpMa = a->maPhong;
    a->maPhong = b->maPhong;
    b->maPhong = tmpMa;

    int tmpTinhTrang = a->tinhTrang;
    a->tinhTrang = b->tinhTrang;
    b->tinhTrang = tmpTinhTrang;

    char *tmpTen = a->tenPhong;
    a->tenPhong = b->tenPhong;
    b->tenPhong = tmpTen;
}

void sapXepTangDanTheoTen(node **head) {
    if (*head == NULL || (*head)->next == NULL) return;

    for (node *i = *head; i != NULL; i = i->next) {
        node *min = i;
        for (node *j = i->next; j != NULL; j = j->next) {
            if (strcmp(j->data.tenPhong, min->data.tenPhong) < 0) {
                min = j;
            }
        }
        if (min != i) {
            swap(&i->data, &min->data);
        }
    }
}

node* xoaPhongCoMaLaX(node **head, int x) {
    node *tmp = *head, *prev = NULL;
    while (tmp != NULL) {
        if (tmp->data.maPhong == x) {
            if (prev == NULL) {
                *head = tmp->next;
            } else {
                prev->next = tmp->next;
            }
            node *toFree = tmp;
            tmp = tmp->next;
            free(toFree->data.tenPhong);
            free(toFree);
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }

    return *head;
}

void thongTinPhongThuK(node *head, int n) {
    int pos;
    while (1) {
        printf("Nhap vi tri can xuat thong tin phong (1 den %d): ", n);
        if (scanf("%d", &pos) == 1 && pos >= 1 && pos <= n) {
            break;
        }
        printf("Vui long nhap vi tri hop le!\n");
        xoaBoDem();
    }
    xoaBoDem();

    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }

    node *tmp = head;
    int i = 1;
    while (tmp != NULL && i < pos) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL) {
        printf("Vi tri %d khong ton tai!\n", pos);
        return;
    }

    printf("Thong tin phong thu %d:\n", pos);
    xuatMotPhong(&tmp->data);
}

node* themPhongOViTriCuThe(node **head, int n) {
    int pos;
    while (1) {
        printf("Nhap vi tri can them phong (1 den %d): ", n + 1);
        if (scanf("%d", &pos) == 1 && pos >= 1 && pos <= n + 1) {
            break;
        }
        printf("Vui long nhap vi tri hop le!\n");
        xoaBoDem();
    }
    xoaBoDem();

    phong val;
    nhapMotPhong(&val);

    if (pos == 1) {
        node *newNode = taoNode(val);
        newNode->next = *head;
        *head = newNode;
        free(val.tenPhong);

        return *head;
    }

    node *tmp = *head;
    int i = 1;
    while (tmp != NULL && i < pos - 1) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL && i < pos - 1) {
        printf("Vi tri %d khong hop le!\n", pos);
        free(val.tenPhong);
        return *head;
    }

    node *newNode = taoNode(val);
    newNode->next = tmp->next;
    tmp->next = newNode;
    free(val.tenPhong);

    return *head;
}

void giaiPhongDanhSach(node **head) {
    while (*head != NULL) {
        node *tmp = *head;
        *head = tmp->next;
        free(tmp->data.tenPhong);
        free(tmp);
    }
}

int main() {
    node *head = NULL;
    int n = 0, choice;
    while (1) {
        printf("\n=== QUAN LY PHONG ===\n");
        printf("1. Nhap danh sach phong\n");
        printf("2. Xuat danh sach phong\n");
        printf("3. Them phong tai vi tri\n");
        printf("4. Xoa phong theo ma\n");
        printf("5. Sap xep theo ten\n");
        printf("6. Tim phong con trong\n");
        printf("7. Dem phong da dat\n");
        printf("8. Xuat thong tin phong thu k\n");
        printf("9. Thoat\n");
        printf("Chon: ");
        if (scanf("%d", &choice) != 1) {
            xoaBoDem();
            continue;
        }
        xoaBoDem();

        switch (choice) {
            case 1:
                nhapSoLuongPhong(&n);
                nhapDanhSachPhong(&head, n);
                break;
            case 2:
                printf("Danh sach phong:\n");
                xuatDanhSachPhong(head);
                break;
            case 3:
                themPhongOViTriCuThe(&head, n);
                n++;
                break;
            case 4: {
                int ma;
                printf("Nhap ma phong can xoa: ");
                if (scanf("%d", &ma) == 1) {
                    xoaPhongCoMaLaX(&head, ma);
                    printf("Da xoa phong co ma %d (neu ton tai).\n", ma);
                } else {
                    printf("Ma phong khong hop le!\n");
                }
                xoaBoDem();
                break;
            }
            case 5:
                sapXepTangDanTheoTen(&head);
                printf("Da sap xep theo ten!\n");
                xuatDanhSachPhong(head);
                break;
            case 6: {
                node *empty = timPhongDauTienConTrong(head);
                if (empty) {
                    printf("Phong con trong dau tien:\n");
                    xuatMotPhong(&empty->data);
                } else {
                    printf("Khong co phong con trong!\n");
                }
                break;
            }
            case 7:
                printf("So phong da dat: %d\n", demSoLuongPhongDaDat(head));
                break;
            case 8:
                thongTinPhongThuK(head, n);
                break;
            case 9:
                giaiPhongDanhSach(&head);
                printf("Da giai phong danh sach. Thoat!\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
}
