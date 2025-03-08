#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maSV[10];
    char hoTen[50];
    float diemTB;
} SinhVien;

typedef struct node {
    SinhVien info;
    struct node *next;
} Node;

void KhoiTaoDanhSach(Node **phead) {
    *phead = NULL;
}

int DanhSachRong(Node *phead) {
    return phead == NULL;
}

void NhapThongTinSV(SinhVien *sv) {
    printf("Nhập mã sinh viên: ");
    scanf("%s", sv->maSV);
    printf("Nhập họ tên: ");
    getchar();
    fgets(sv->hoTen, 50, stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0;
    printf("Nhập điểm trung bình: ");
    scanf("%f", &sv->diemTB);
}

Node* TaoNodeMoi(SinhVien sv) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không đủ bộ nhớ!\n");
        return NULL;
    }
    newNode->info = sv;
    newNode->next = NULL;
    return newNode;
}

void ThemVaoDau(Node **phead, SinhVien sv) {
    Node *newNode = TaoNodeMoi(sv);
    if (newNode == NULL) {
        return;
    }
    newNode->next = *phead;
    *phead = newNode;
}

void NhapDanhSachSV(Node **phead) {
    int n;
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        printf("Nhập thông tin sinh viên thứ %d:\n", i + 1);
        NhapThongTinSV(&sv);
        ThemVaoDau(phead, sv);
    }
}

void XuatDanhSachSV(Node *phead) {
    Node *current = phead;
    while (current != NULL) {
        printf("Mã SV: %s, Họ tên: %s, Điểm TB: %.2f\n", current->info.maSV, current->info.hoTen, current->info.diemTB);
        current = current->next;
    }
}

void XuatSVDiemTBLonHon5(Node *phead) {
    Node *current = phead;
    while (current != NULL) {
        if (current->info.diemTB > 5) {
            printf("Mã SV: %s, Họ tên: %s, Điểm TB: %.2f\n", current->info.maSV, current->info.hoTen, current->info.diemTB);
        }
        current = current->next;
    }
}

int main() {
    Node *head;
    KhoiTaoDanhSach(&head);

    NhapDanhSachSV(&head);
    printf("\nDanh sách sinh viên:\n");
    XuatDanhSachSV(head);

    printf("\nDanh sách sinh viên có điểm trung bình lớn hơn 5:\n");
    XuatSVDiemTBLonHon5(head);

    return 0;
}
