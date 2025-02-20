#include <stdio.h>
#define MAX 100  


void nhapSL(int *n) {
    do {
        printf("Nhap so luong phan tu n (0 < n <= %d): ", MAX);
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX);
}

void nhapDS(int a[], int n) {
    printf("Nhap %d phan tu cua day so:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void xuatDS(int a[], int n) {
    printf("Day so: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


void nhapX(int *x) {
    printf("Nhap gia tri x can tim: ");
    scanf("%d", x);
}


int timTuanTu(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;  
        }
    }
    return -1;
}


void sapXep(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


int timNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  
}


int main() {
    int a[MAX], n, x, viTri;
    

    nhapSL(&n);
    nhapDS(a, n);
    

    xuatDS(a, n);
    
    
    nhapX(&x);
    viTri = timTuanTu(a, n, x);
    if (viTri != -1)
        printf("Tim thay x = %d tai vi tri %d \n", x, viTri);
    else
        printf("Khong tim thay x = %d \n", x);
    

    sapXep(a, n);
    printf("Day so sau khi sap xep: ");
    xuatDS(a, n);
    
    
    viTri = timNhiPhan(a, n, x);
    if (viTri != -1)
        printf("Tim thay x = %d tai vi tri %d\n", x, viTri);
    else
        printf("Khong tim thay x = %d\n", x);
    
    return 0;
}

