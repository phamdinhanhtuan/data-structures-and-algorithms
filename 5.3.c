#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    int maSV;
    char tenSV[50];
    struct SinhVien *next;
} SinhVien;

SinhVien *themSinhVien(SinhVien *head, int ma, char *ten) {
    SinhVien *newSV = (SinhVien *)malloc(sizeof(SinhVien));
    newSV->maSV = ma;
    strcpy(newSV->tenSV, ten);
    newSV->next = NULL;

    if (head == NULL) return newSV;

    SinhVien *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newSV;
    return head;
}

void xuatDanhSach(SinhVien *head) {
    SinhVien *temp = head;
    while (temp) {
        printf("Ma SV: %d, Ten SV: %s\n", temp->maSV, temp->tenSV);
        temp = temp->next;
    }
}

int demSinhVien(SinhVien *head) {
    int count = 0;
    SinhVien *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void xuatSinhVienThuK(SinhVien *head, int k) {
    SinhVien *temp = head;
    int count = 1;
    while (temp) {
        if (count == k) {
            printf("Thong tin sinh vien thu %d: Ma SV: %d, Ten SV: %s\n", k, temp->maSV, temp->tenSV);
            return;
        }
        temp = temp->next;
        count++;
    }
    printf("Khong tim thay sinh vien thu %d!\n", k);
}

int main() {
    SinhVien *danhSach = NULL;
    int chon, ma, k;
    char ten[50];

    do {
        printf("\n===== MENU =====\n");
        printf("1. Them sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Dem so luong sinh vien\n");
        printf("4. Xuat thong tin sinh vien thu k\n");
        printf("5. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                printf("Nhap ma SV: ");
                scanf("%d", &ma);
                getchar();
                printf("Nhap ten SV: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = 0;
                danhSach = themSinhVien(danhSach, ma, ten);
                break;
            case 2:
                printf("\nDanh sach sinh vien:\n");
                xuatDanhSach(danhSach);
                break;
            case 3:
                printf("\nSo luong sinh vien: %d\n", demSinhVien(danhSach));
                break;
            case 4:
                printf("Nhap vi tri k: ");
                scanf("%d", &k);
                xuatSinhVienThuK(danhSach, k);
                break;
            case 5:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 5);

    return 0;
}
