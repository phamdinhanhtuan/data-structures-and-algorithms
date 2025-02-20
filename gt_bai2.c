#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void nhapSL(int *n) {
    do {
        printf("Nhap so luong phan tu (0 < n <= %d): ", MAX);
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX);
}

void sinhDS(int a[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void xuatDS(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void sapXepGiamDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int timKiemNhiPhan(int a[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x)
            return m;
        if (a[m] < x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

void xoaTaiVT(int a[], int *n, int k) {
    for (int i = k; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

void xoaPhanTuX(int a[], int *n, int x) {
    int pos = timKiemNhiPhan(a, 0, *n - 1, x);
    if (pos == -1) {
        printf("Khong tim thay phan tu %d trong day so.\n", x);
    } else {
        xoaTaiVT(a, n, pos);
        printf("Da xoa phan tu %d khoi day so.\n", x);
    }
}

void menu(int *chon) {
    printf("\n0: Thoat chuong trinh");
    printf("\n1: Sinh day so");
    printf("\n2: Xuat day so");
    printf("\n3: Sap xep giam dan");
    printf("\n4: Tim x");
    printf("\n5: Xoa x");
    printf("\nBan hay chon: ");
    scanf("%d", chon);
}

int main() {
    int a[MAX];
    int n, chon, x;

    nhapSL(&n);

    do {
        menu(&chon);
        switch (chon) {
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            case 1:
                sinhDS(a, n);
                printf("Da sinh day so ngau nhien.\n");
                break;
            case 2:
                xuatDS(a, n);
                break;
            case 3:
                sapXepGiamDan(a, n);
                printf("Da sap xep day so giam dan.\n");
                break;
            case 4:
                printf("Nhap gia tri x can tim: ");
                scanf("%d", &x);
                int result = timKiemNhiPhan(a, 0, n - 1, x);
                if (result == -1)
                    printf("Khong tim thay %d trong day so.\n", x);
                else
                    printf("Tim thay %d tai vi tri %d.\n", x, result);
                break;
            case 5:
                printf("Nhap gia tri x can xoa: ");
                scanf("%d", &x);
                xoaPhanTuX(a, &n, x);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (chon != 0);

    return 0;
}