#include <stdio.h>


void nhapSL(int *n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);
}


void nhapDS(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// Function to print the array
void xuatDS(int n, int a[]) {
    printf("Danh sach cac phan tu: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to count occurrences of x in array a[]
int demLanXuatHien(int n, int a[], int x) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            dem++;
        }
    }
    return dem;
}

int main() {
    int n, x;
    int a[100];
    nhapSL(&n);

    nhapDS(n, a);


    xuatDS(n, a);

    
    printf("Nhap so can dem: ");
    scanf("%d", &x);

    
    printf("So lan xuat hien cua %d la: %d\n", x, demLanXuatHien(n, a, x));

    return 0;
}
