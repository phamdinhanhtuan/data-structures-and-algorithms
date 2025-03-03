#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sinhVien {
    char msv[11];
    char ht[41];
    float dtb;
} SV;

void nhapSL(int *n) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
}

void nhapThongTin(SV *sv) {
    printf("\nNhap ma so sinh vien: ");
    scanf("%s", sv->msv);
    printf("Nhap ho va ten: ");
    while (getchar() != '\n');  // Clear input buffer
    fgets(sv->ht, sizeof(sv->ht), stdin);
    sv->ht[strcspn(sv->ht, "\n")] = 0;  // Remove newline character from fgets
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->dtb);
}

void nhapDS(SV a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap sinh vien thu %d:\n", i + 1);
        nhapThongTin(&a[i]);
    }
}

void xuatThongTin(SV *sv) {
    printf("\nMa so sinh vien: %s", sv->msv);
    printf("\nHo va ten: %s", sv->ht);
    printf("\nDiem trung binh: %.2f\n", sv->dtb);
}

void xuatDS(SV a[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        xuatThongTin(&a[i]);
    }
}

void nhapX(char x[]) {
    printf("\nNhap ma so sinh vien can tim: ");
    scanf("%s", x);
}

int linearSearch(SV a[], int n, char x[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].msv, x) == 0) {
            return i;
        }
    }
    return -1;
}

void sapXep(SV a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i].msv, a[j].msv) > 0) {  // Sort ascending by student ID
                SV temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int binarySearch(SV a[], int n, char x[]) {
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        int cmp = strcmp(a[m].msv, x);
        if (cmp == 0) {
            return m;
        } else if (cmp < 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    nhapSL(&n);

    SV *a = (SV *)malloc(n * sizeof(SV));
    if (a == NULL) {
        printf("Khong the cap phat bo nho!");
        return -1;
    }

    nhapDS(a, n);
    xuatDS(a, n);

    char x[11];
    nhapX(x);

    int vt = linearSearch(a, n, x);
    if (vt == -1) {
        printf("\nKhong tim thay sinh vien co ma %s.\n", x);
    } else {
        printf("\nTim thay sinh vien co ma %s tai vi tri %d:\n", x, vt);
        xuatThongTin(&a[vt]);
    }

    sapXep(a, n);
    printf("\nDanh sach sau khi sap xep:\n");
    xuatDS(a, n);

    int viTri = binarySearch(a, n, x);
    if (viTri == -1) {
        printf("\nKhong tim thay sinh vien co ma %s sau khi sap xep.\n", x);
    } else {
        printf("\nTim thay sinh vien co ma %s tai vi tri %d sau khi sap xep:\n", x, viTri);
        xuatThongTin(&a[viTri]);
    }

    free(a);
    return 0;
}
