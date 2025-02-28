#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút
typedef struct node {
    int info;
    struct node *next;
} Node;

// Khởi tạo danh sách liên kết
void KhoiTaoDanhSach(Node **phead) {
    *phead = NULL;
}

// Kiểm tra danh sách có rỗng hay không
int DanhSachRong(Node *phead) {
    return phead == NULL;
}

// Tạo một node mới với dữ liệu x
Node* TaoNodeMoi(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không đủ bộ nhớ!\n");
        return NULL;
    }
    newNode->info = x;
    newNode->next = NULL;
    return newNode;
}

// Thêm phần tử mới vào đầu danh sách
void ThemVaoDau(Node **phead, int x) {
    Node *newNode = TaoNodeMoi(x);
    if (newNode == NULL) {
        return;
    }
    newNode->next = *phead;
    *phead = newNode;
}

// Nhập danh sách số nguyên
void NhapDanhSach(Node **phead) {
    int n, x;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", &x);
        ThemVaoDau(phead, x);
    }
}

// Xuất danh sách số nguyên
void XuatDanhSach(Node *phead) {
    Node *current = phead;
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head;
    KhoiTaoDanhSach(&head);

    NhapDanhSach(&head);
    printf("Danh sách vừa nhập: ");
    XuatDanhSach(head);

    return 0;
}
