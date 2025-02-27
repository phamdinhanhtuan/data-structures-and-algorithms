#include <stdio.h>
#include <string.h>

#define MAX_NHANVIEN 100 
#define MAX_MA 10      
#define MAX_HO_TEN 30   


struct NhanVien {
    char maNV[MAX_MA];
    char hoTen[MAX_HO_TEN];
    long luong;
};

void nhapNhanVien(struct NhanVien *nv) {
    printf("Nhap ma nhan vien: ");
    gets(nv->maNV); 

    printf("Nhap ho ten: ");
    gets(nv->hoTen); 

    printf("Nhap luong: ");
    scanf("%ld", &nv->luong);
    getchar(); 
}


void nhapDanhSach(struct NhanVien ds[], int *n) {
    printf("Nhap so luong nhan vien (toi da %d): ", MAX_NHANVIEN);
    scanf("%d", n);
    getchar(); 

    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin nhan vien thu %d:\n", i + 1);
        nhapNhanVien(&ds[i]);
    }
}


void xuatNhanVien(struct NhanVien nv) {
    printf("%s  %s  %ld\n", nv.maNV, nv.hoTen, nv.luong);
}


void xuatDanhSach(struct NhanVien ds[], int n) {
    printf("\nDanh sach nhan vien:\n");
    printf("Ma NV    Ho ten    Luong\n");
    printf("\n");
    for (int i = 0; i < n; i++) {
        xuatNhanVien(ds[i]);
    }
}


void interchangeSortLuong(struct NhanVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].luong > ds[j].luong) {
                struct NhanVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}


void interchangeSortHoTen(struct NhanVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ds[i].hoTen, ds[j].hoTen) > 0) {
                struct NhanVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}


void bubbleSortLuong(struct NhanVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].luong > ds[j + 1].luong) {
                struct NhanVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}


void bubbleSortHoTen(struct NhanVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(ds[j].hoTen, ds[j + 1].hoTen) > 0) {
                struct NhanVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}


int main() {
    struct NhanVien ds[MAX_NHANVIEN];
    int n;

    
    nhapDanhSach(ds, &n);

    
    xuatDanhSach(ds, n);

    
    interchangeSortLuong(ds, n);
    printf("\nSap xep theo luong (Interchange Sort):\n");
    xuatDanhSach(ds, n);


    interchangeSortHoTen(ds, n);
    printf("\nSap xep theo ho ten (Interchange Sort):\n");
    xuatDanhSach(ds, n);


    bubbleSortLuong(ds, n);
    printf("\nSap xep theo luong (Bubble Sort):\n");
    xuatDanhSach(ds, n);


    bubbleSortHoTen(ds, n);
    printf("\nSap xep theo ho ten (Bubble Sort):\n");
    xuatDanhSach(ds, n);

    return 0;
}
