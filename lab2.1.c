#include <stdio.h>
#include <string.h>
#define MAX 100


typedef struct {
    char maSV[10];
    char hoTen[40];
    float diemTB;
} SinhVien;


void NhapSL(int &n) {
    do {
        printf("Nhap so luong sinh vien (0 < n <= %d): ", MAX);
        scanf("%d", &n);
    } while (n <= 0 || n > MAX);
}


void Nhap1SV(SinhVien &sv) {
    printf("Nhap ma sinh vien: ");
    scanf(" %[^\n]", sv.maSV);
    printf("Nhap ho ten: ");
    scanf(" %[^\n]", sv.hoTen);
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv.diemTB);
}


void NhapDS(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        Nhap1SV(a[i]);
    }
}


void Xuat1SV(SinhVien &sv) {
    printf("Ma SV: %s, Ho ten: %s, Diem TB: %.2f\n", sv.maSV, sv.hoTen, sv.diemTB);
}


void XuatDS(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        Xuat1SV(a[i]);
    }
}


void NhapMaSV(char x[]) {
    printf("Nhap ma sinh vien can tim: ");
    scanf(" %[^\n]", x);
}


int TimTuanTu(SinhVien a[], int n, char x[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].maSV, x) == 0) {
            return i;
        }
    }
    return -1;
}


void SapXep(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i].maSV, a[j].maSV) > 0) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


int TimNhiPhan(SinhVien a[], int n, char x[]) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(a[mid].maSV, x) == 0) {
            return mid;
        } else if (strcmp(a[mid].maSV, x) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


void XuatSVTheoHoTen(SinhVien a[], int n, char y[]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].hoTen, y) == 0) {
            Xuat1SV(a[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong sinh vien nao co ho ten nhu vay.\n");
    }
}


void XuatSVDiemCaoNhat(SinhVien a[], int n) {
    float maxDTB = a[0].diemTB;
    for (int i = 1; i < n; i++) {
        if (a[i].diemTB > maxDTB) {
            maxDTB = a[i].diemTB;
        }
    }
    printf("Sinh vien co diem trung binh cao nhat (%.2f):\n", maxDTB);
    for (int i = 0; i < n; i++) {
        if (a[i].diemTB == maxDTB) {
            Xuat1SV(a[i]);
        }
    }
}

// Hàm main
int main() {
    SinhVien a[MAX];
    int n;
    char x[10], y[40];


    NhapSL(n);
    NhapDS(a, n);


    printf("\nDanh sach sinh vien:\n");
    XuatDS(a, n);


    NhapMaSV(x);
    int indexTT = TimTuanTu(a, n, x);
    if (indexTT != -1) {
        printf("Tim thay sinh vien co ma %s (tim tuan tu):\n", x);
        Xuat1SV(a[indexTT]);
    } else {
        printf("Khong tim thay sinh vien co ma %s (tim tuan tu).\n", x);
    }


    SapXep(a, n);
    printf("\nDanh sach sau khi sap xep:\n");
    XuatDS(a, n);

    NhapMaSV(x);
    int indexNP = TimNhiPhan(a, n, x);
    if (indexNP != -1) {
        printf("Tim thay sinh vien co ma %s (tim nhi phan):\n", x);
        Xuat1SV(a[indexNP]);
    } else {
        printf("Khong tim thay sinh vien co ma %s (tim nhi phan).\n", x);
    }


    printf("\nNhap ho ten can tim: ");
    scanf(" %[^\n]", y);
    XuatSVTheoHoTen(a, n, y);


    printf("\n");
    XuatSVDiemCaoNhat(a, n);

    return 0;
}
