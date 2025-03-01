#include <stdio.h>
#include <stdlib.h>

typedef struct qlsv {
    char msv[11], ht[31];
    float luong;
}q;

void nhapsl(int *n) {
    do {
        printf("Nhap vao so luong phan tu: ");
        scanf("%d", n);
    } while (*n < 0);
}

void capphatdong(q **ptr, int n) {
    *ptr = (q *)calloc(n, sizeof(q));

    if (*ptr == NULL) {
        printf("ERR");
        exit(1);
    }
}

void nhap1sv(q *i) {
    printf("Nhap vao ma sinh vien: ");
    scanf("%s", i->msv);
    while (getchar() != '\n');
    printf("Nhap vao ten sinh vien: ");
    fgets(i->ht, sizeof(i->ht), stdin);
    printf("Nhap vao luong sinh vien: ");
    scanf("%f", &i->luong);
}

void xuat1sv(q i) {
    printf("Ma sinh vien la: %s\n", i.msv);
    printf("Ten sinh vien la: %s", i.ht);
    printf("Luong cua sinh vien la: %.2f\n", i.luong);
}

void nhapmang(q *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap vao sinh vien thu %d:\n", i + 1);
        nhap1sv(&a[i]);
    }
}

void xuatmang(q *a, int n) {
    for (int i = 0; i < n; i++) {
        xuat1sv(a[i]);
    }
}

void swap(q *a, q *b) {
    q tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionIncrease(q *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].luong < a[min].luong) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void selectionDecrease(q *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].luong > a[min].luong) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void insertionIncrease(q *a, int n) {
    for (int i = 1; i < n; i++) {
        q key = a[i];
        int pos = i - 1;
        while (pos >= 0 && key.luong < a[pos].luong) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = key;
    }
}

void insertionDecrease(q *a, int n) {
    for (int i = 1; i < n; i++) {
        q key = a[i];
        int pos = i - 1;
        while (pos >= 0 && key.luong > a[pos].luong) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = key;
    } 
}

int main() {
    int n;
    q *ptr;

    nhapsl(&n);
    capphatdong(&ptr, n);
    nhapmang(ptr, n);
    
    printf("\nDanh sach sinh vien vua nhap:\n");
    xuatmang(ptr, n);

    printf("\nSelection tang dan luong:\n");
    selectionIncrease(ptr, n);
    xuatmang(ptr, n);

    printf("\nSelection giam dan luong:\n");
    selectionDecrease(ptr, n);
    xuatmang(ptr, n);

    printf("\nInsertion tang dan luong:\n");
    insertionIncrease(ptr, n);
    xuatmang(ptr, n);

    printf("\nInsertion giam dan luong:\n");
    insertionDecrease(ptr, n);
    xuatmang(ptr, n);

    free(ptr);
    return 0;
}
