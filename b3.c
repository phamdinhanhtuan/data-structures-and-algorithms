#include <stdio.h>
#include <string.h>
#define MAX 100

// Định nghĩa kiểu dữ liệu DauSach
typedef struct {
    int maSach;
    char tenSach[40];
} DauSach;

// Hàm nhập số lượng đầu sách
void NhapSL(int &n) {
    do {
        printf("Nhap so luong dau sach (0 < n <= %d): ", MAX);
        scanf("%d", &n);
    } while (n <= 0 || n > MAX);
}

// Hàm nhập thông tin 1 đầu sách
void Nhap1Sach(DauSach &d) {
    printf("Nhap ma sach: ");
    scanf("%d", &d.maSach);
    printf("Nhap ten sach: ");
    scanf(" %[^\n]", d.tenSach);
}

// Hàm nhập danh sách đầu sách
void NhapDS(DauSach a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin dau sach thu %d:\n", i + 1);
        Nhap1Sach(a[i]);
    }
}

// Hàm xuất thông tin 1 đầu sách
void Xuat1Sach(DauSach &d) {
    printf("Ma sach: %d, Ten sach: %s\n", d.maSach, d.tenSach);
}

// Hàm xuất danh sách đầu sách
void XuatDS(DauSach a[], int n) {
    for (int i = 0; i < n; i++) {
        Xuat1Sach(a[i]);
    }
}

// Hàm nhập mã sách cần tìm
void NhapMaSach(int &x) {
    printf("Nhap ma sach can tim: ");
    scanf("%d", &x);
}

// Hàm tìm kiếm tuần tự
int TimTuanTu(DauSach a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i].maSach == x) {
            return i;
        }
    }
    return -1;
}

// Hàm sắp xếp danh sách tăng dần theo mã sách
void SapXep(DauSach a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].maSach > a[j].maSach) {
                DauSach temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Hàm tìm kiếm nhị phân
int TimNhiPhan(DauSach a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid].maSach == x) {
            return mid;
        } else if (a[mid].maSach < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Hàm main
int main() {
    DauSach a[MAX];
    int n, x;

    // Nhập danh sách đầu sách
    NhapSL(n);
    NhapDS(a, n);

    // Xuất danh sách đầu sách
    printf("\nDanh sach dau sach:\n");
    XuatDS(a, n);

    // Tìm kiếm tuần tự
    NhapMaSach(x);
    int indexTT = TimTuanTu(a, n, x);
    if (indexTT != -1) {
        printf("Tim thay dau sach co ma %d (tim tuan tu):\n", x);
        Xuat1Sach(a[indexTT]);
    } else {
        printf("Khong tim thay dau sach co ma %d (tim tuan tu).\n", x);
    }

    // Tìm kiếm nhị phân
    SapXep(a, n);
    printf("\nDanh sach sau khi sap xep:\n");
    XuatDS(a, n);

    NhapMaSach(x);
    int indexNP = TimNhiPhan(a, n, x);
    if (indexNP != -1) {
        printf("Tim thay dau sach co ma %d (tim nhi phan):\n", x);
        Xuat1Sach(a[indexNP]);
    } else {
        printf("Khong tim thay dau sach co ma %d (tim nhi phan).\n", x);
    }

    return 0;
}
