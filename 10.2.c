#include <stdio.h>

void timNhiPhan(int a[], int n, int x) {
    int dau = 0, cuoi = n - 1, giua;

    while (dau <= cuoi) {
        giua = (dau + cuoi) / 2;
        printf("dau = %d, cuoi = %d, giua = %d, a[giua] = %d\n", dau, cuoi, giua, a[giua]);

        if (a[giua] == x) {
            printf("Tim thay %d tai vi tri %d\n", x, giua);
            return;
        } else if (a[giua] < x) {
            dau = giua + 1;
        } else {
            cuoi = giua - 1;
        }
    }
    printf("Khong tim thay %d trong mang\n", x);
}

int main() {
    int a[] = {3, 6, 7, 11, 18, 22, 23, 45}; // Sorted array
    int n = sizeof(a) / sizeof(a[0]);
    int x = 22;

    printf("Tim kiem nhi phan cho %d:\n", x);
    timNhiPhan(a, n, x);

    return 0;
}
