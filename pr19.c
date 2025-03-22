#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct qlsv {
    char msv[11], ht[31];
    float luong;
} q;

void nhapsl(int *n) {
    do {
        printf("Nhap vao so luong sinh vien: ");
        scanf("%d", n);
    } while (*n <= 0);
}

void capphatdong(q **ptr, int n) {
    *ptr = (q *)calloc(n, sizeof(q));
    if (*ptr == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
}

void nhap1sv(q *i) {
    printf("Nhap vao ma sinh vien: ");
    scanf("%s", i->msv);
    while (getchar() != '\n'); 
    printf("Nhap vao ten sinh vien: ");
    fgets(i->ht, sizeof(i->ht), stdin);
    i->ht[strcspn(i->ht, "\n")] = 0;
    printf("Nhap vao luong sinh vien: ");
    scanf("%f", &i->luong);
}

void xuat1sv(q i) {
    printf("Ma SV: %s , Ten SV: %s , Luong SV: %.2f\n", i.msv, i.ht, i.luong);
}

void nhapmang(q *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap sinh vien thu %d!\n", i + 1);
        nhap1sv(&a[i]);
    }
}

void xuatmang(q *a, int n) {
    printf("\nDanh sach sinh vien!\n");
    for (int i = 0; i < n; i++) {
        xuat1sv(a[i]);
    }
}

void swap(q *a, q *b) {
    q tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(q *a, int n , int isIncrease) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if ((isIncrease && a[j].luong < a[min].luong) || (!isIncrease && a[j].luong > a[min].luong)) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

int partition(q *a, int l, int r, int isIncrease) {
    float pivot = a[r].luong;
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if ((isIncrease && a[j].luong < pivot) || (!isIncrease && a[j].luong > pivot)) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return i + 1;
}

void quickSort(q *a, int l, int r, int isIncrease) {
    if (l < r) {
        int pi = partition(a, l, r, isIncrease);
        quickSort(a, l, pi - 1, isIncrease);
        quickSort(a, pi + 1, r, isIncrease);
    }
}

void menu() {
    printf("\n======= MENU =======\n");
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Sap xep (Selection Sort)\n");
    printf("4. Sap xep (Quick Sort)\n");
    printf("0. Thoat\n");
    printf("====================\n");
}

int main() {
    int n, choice, isIncrease;
    q *ptr = NULL;

    while (1) {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                nhapsl(&n);
                capphatdong(&ptr, n);
                nhapmang(ptr, n);
                break;
            case 2: 
                if (ptr) xuatmang(ptr, n);
                else printf("Danh sach rong!\n");
                break;
            case 3: 
                if (ptr) {
                    printf("Nhap kieu sap xep (0: Giam, 1: Tang): ");
                    scanf("%d", &isIncrease);
                    selectionSort(ptr, n, isIncrease);
                    printf("Da sap xep danh sach theo Selection Sort.\n");
                } else {
                    printf("Danh sach rong!\n");
                }
                break;
            case 4:
                if (ptr) {
                    printf("Nhap kieu sap xep (0: Giam, 1: Tang): ");
                    scanf("%d", &isIncrease);
                    quickSort(ptr, 0, n - 1, isIncrease);
                    printf("Da sap xep danh sach theo Quick Sort.\n");
                } else {
                    printf("Danh sach rong!\n");
                }
                break;
            case 0:
                free(ptr);
                printf("Thoat chuong trinh!\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}
