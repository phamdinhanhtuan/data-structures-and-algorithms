#include <stdio.h>
#define MAX 100


typedef struct ThongtinSach {
    int masach;
    char tensach[40];
} DauSach;


typedef struct DanhSach {
    int sl; // Số lượng phần tử của danh sách
    DauSach a[MAX]; // Mảng chứa các đầu sách
} List;


void Nhap1Sach(DauSach &d) {
    printf("Nhap ma sach: ");
    scanf("%d", &d.masach);
    printf("Nhap ten sach: ");
    scanf(" %[^\n]", d.tensach);
}


void NhapDS(List &l) {
    do {
        printf("Nhap so luong dau sach (0 < n <= %d): ", MAX);
        scanf("%d", &l.sl);
    } while (l.sl <= 0 || l.sl > MAX);

    for (int i = 0; i < l.sl; i++) {
        printf("Nhap thong tin dau sach thu %d:\n", i + 1);
        Nhap1Sach(l.a[i]);
    }
}


void Xuat1Sach(DauSach &d) {
    printf("Ma sach: %d, Ten sach: %s\n", d.masach, d.tensach);
}


void XuatDS(List &l) {
    for (int i = 0; i < l.sl; i++) {
        Xuat1Sach(l.a[i]);
    }
}


void NhapMaSach(int &x) {
    printf("Nhap ma sach can tim: ");
    scanf("%d", &x);
}


int TimTuanTu(List &l, int x) {
    for (int i = 0; i < l.sl; i++) {
        if (l.a[i].masach == x) {
            return i;
        }
    }
    return -1;
}


void SapXep(List &l) {
    for (int i = 0; i < l.sl - 1; i++) {
        for (int j = i + 1; j < l.sl; j++) {
            if (l.a[i].masach > l.a[j].masach) {
                DauSach temp = l.a[i];
                l.a[i] = l.a[j];
                l.a[j] = temp;
            }
        }
    }
}


int TimNhiPhan(List &l, int x) {
    int left = 0, right = l.sl - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (l.a[mid].masach == x) {
            return mid;
        } else if (l.a[mid].masach < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Hàm main
int main() {
    List l;
    int x;


    NhapDS(l);


    printf("\nDanh sach dau sach:\n");
    XuatDS(l);


    NhapMaSach(x);
    int indexTT = TimTuanTu(l, x);
    if (indexTT != -1) {
        printf("Tim thay dau sach co ma %d (tim tuan tu):\n", x);
        Xuat1Sach(l.a[indexTT]);
    } else {
        printf("Khong tim thay dau sach co ma %d (tim tuan tu).\n", x);
    }


    SapXep(l);
    printf("\nDanh sach sau khi sap xep:\n");
    XuatDS(l);

    NhapMaSach(x);
    int indexNP = TimNhiPhan(l, x);
    if (indexNP != -1) {
        printf("Tim thay dau sach co ma %d (tim nhi phan):\n", x);
        Xuat1Sach(l.a[indexNP]);
    } else {
        printf("Khong tim thay dau sach co ma %d (tim nhi phan).\n", x);
    }

    return 0;
}
