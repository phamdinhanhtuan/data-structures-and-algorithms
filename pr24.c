#include <stdio.h>    // Thư viện cho printf, scanf
#include <stdlib.h>   // Thư viện cho malloc, free, NULL
#include <string.h>   // Thư viện cho các hàm xử lý chuỗi

// Định nghĩa cấu trúc cho một mặt hàng
struct MatHang {
    char maHang[10];      // Mã mặt hàng
    char tenHang[50];     // Tên mặt hàng  
    int soLuong;          // Số lượng
    struct MatHang* next; // Con trỏ đến node tiếp theo
};

typedef struct MatHang* LinkedList;

// 1. Kiểm tra danh sách rỗng
int isEmpty(LinkedList list) {
    return (list == NULL);
}

// 2. Đếm số lượng node trong danh sách
int demSoNode(LinkedList list) {
    int count = 0;
    LinkedList current = list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// 3. Tạo node mới
struct MatHang* taoNode(char* ma, char* ten, int sl) {
    struct MatHang* newNode = (struct MatHang*)malloc(sizeof(struct MatHang));
    if (newNode == NULL) {
        printf("Loi: Khong the cap phat bo nho!\n");
        exit(1);
    }
    strcpy(newNode->maHang, ma);
    strcpy(newNode->tenHang, ten);
    newNode->soLuong = sl;
    newNode->next = NULL;
    return newNode;
}

// 4. Nhập danh sách mặt hàng
void nhapDanhSach(LinkedList* list) {
    char ma[10], ten[50];
    int sl;
    char tiepTuc;
    
    do {
        printf("\nNhap thong tin mat hang:\n");
        printf("Nhap ma hang: ");
        scanf("%s", ma);
        printf("Nhap ten hang: ");
        scanf(" %s", ten);
        printf("Nhap so luong: ");
        scanf("%d", &sl);
        
        // Tạo node mới và thêm vào đầu danh sách
        struct MatHang* newNode = taoNode(ma, ten, sl);
        newNode->next = *list;
        *list = newNode;
        
        printf("Ban co muon nhap tiep khong? (y/n): ");
        scanf(" %c", &tiepTuc);
     } while (tiepTuc == 'y' || tiepTuc == 'Y');
}

// 5. Xuất danh sách mặt hàng
void xuatDanhSach(LinkedList list) {
    if (isEmpty(list)) {
        printf("\nDanh sach trong!\n");
        return;
    }
    
    printf("\nDanh sach mat hang:\n");
    printf("%-10s %-30s %-10s\n", "Ma hang", "Ten hang", "So luong");
    printf("------------------------------------------------\n");
    
    LinkedList current = list;
    while (current != NULL) {
        printf("%-10s %-30s %-10d\n", 
               current->maHang, 
               current->tenHang, 
               current->soLuong);
        current = current->next;
    }
}

// 6. Tìm mặt hàng theo mã
struct MatHang* timMatHang(LinkedList list, char* maX) {
    LinkedList current = list;
    while (current != NULL) {
        if (strcmp(current->maHang, maX) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 7. Thêm mặt hàng sau mặt hàng có mã X
void themSauMaX(LinkedList* list, char* maX, char* ma, char* ten, int sl) {
    LinkedList current = *list;
    
    // Tìm node có mã X
    while (current != NULL) {
        if (strcmp(current->maHang, maX) == 0) {
            // Tạo node mới và chèn vào sau node hiện tại
            struct MatHang* newNode = taoNode(ma, ten, sl);
            newNode->next = current->next;
            current->next = newNode;
            printf("Da them mat hang moi sau ma %s!\n", maX);
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay mat hang co ma %s!\n", maX);
}

// 8. Xóa mặt hàng đầu danh sách
void xoaDau(LinkedList* list) {
    if (isEmpty(*list)) {
        printf("Danh sach trong, khong the xoa!\n");
        return;
    }
    
    LinkedList temp = *list;
    *list = (*list)->next;
    free(temp);
    printf("Da xoa mat hang dau danh sach!\n");
}

// 9. Xóa toàn bộ danh sách
void xoaDanhSach(LinkedList* list) {
    while (!isEmpty(*list)) {
        xoaDau(list);
    }
    printf("Da xoa toan bo danh sach!\n");
}

// 10. Xóa mặt hàng có mã X
void xoaMatHang(LinkedList* list, char* maX) {
    if (isEmpty(*list)) {
        printf("Danh sach trong!\n");
        return;
    }
    
    // Nếu node đầu là node cần xóa
    if (strcmp((*list)->maHang, maX) == 0) {
        xoaDau(list);
        return;
    }
    
    // Tìm node cần xóa
    LinkedList prev = *list;
    LinkedList current = (*list)->next;
    
    while (current != NULL) {
        if (strcmp(current->maHang, maX) == 0) {
            prev->next = current->next;
            free(current);
            printf("Da xoa mat hang co ma %s!\n", maX);
            return;
        }
        prev = current;
        current = current->next;
    }
    
    printf("Khong tim thay mat hang co ma %s!\n", maX);
}

// 11. Sắp xếp danh sách tăng dần theo tên hàng
void sapXepTheoTen(LinkedList* list) {
    if (isEmpty(*list) || (*list)->next == NULL) {
        return;
    }
    
    LinkedList i, j;
    char tempMa[10], tempTen[50];
    int tempSL;
    
    for (i = *list; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->tenHang, j->tenHang) > 0) {
                // Hoán đổi thông tin
                strcpy(tempMa, i->maHang);
                strcpy(tempTen, i->tenHang);
                tempSL = i->soLuong;
                
                strcpy(i->maHang, j->maHang);
                strcpy(i->tenHang, j->tenHang);
                i->soLuong = j->soLuong;
                
                strcpy(j->maHang, tempMa);
                strcpy(j->tenHang, tempTen);
                j->soLuong = tempSL;
            }
        }
    }
    printf("Da sap xep danh sach theo ten!\n");
}

// Hàm main - Menu chương trình
int main() {
    LinkedList list = NULL;
    int choice;
    char maX[10], ma[10], ten[50];
    int sl;
    
    do {
        printf("\n====== QUAN LY MAT HANG ======\n");
        printf("1. Nhap danh sach mat hang\n");
        printf("2. Xuat danh sach mat hang\n");
        printf("3. Tim mat hang theo ma\n");
        printf("4. Them mat hang sau ma X\n");
        printf("5. Xoa mat hang dau danh sach\n");
        printf("6. Xoa toan bo danh sach\n");
        printf("7. Xoa mat hang co ma X\n");
        printf("8. Sap xep theo ten hang\n");
        printf("0. Thoat chuong trinh\n");
        printf("==============================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                nhapDanhSach(&list);
                break;
            case 2:
                xuatDanhSach(list);
                break;
            case 3:
                printf("Nhap ma can tim: ");
                scanf("%s", maX);
                struct MatHang* kq = timMatHang(list, maX);
                if (kq != NULL) {
                    printf("Tim thay mat hang:\n");
                    printf("Ma hang: %s\n", kq->maHang);
                    printf("Ten hang: %s\n", kq->tenHang);
                    printf("So luong: %d\n", kq->soLuong);
                } else {
                    printf("Khong tim thay mat hang co ma %s!\n", maX);
                }
                break;
            case 4:
                printf("Nhap ma X: ");
                scanf("%s", maX);
                printf("Nhap thong tin mat hang moi:\n");
                printf("Ma hang: ");
                scanf("%s", ma);
                printf("Ten hang: ");
                scanf(" %s", ten);
                printf("So luong: ");
                scanf("%d", &sl);
                themSauMaX(&list, maX, ma, ten, sl);
                break;
            case 5:
                xoaDau(&list);
                break;
            case 6:
                xoaDanhSach(&list);
                break;
            case 7:
                printf("Nhap ma can xoa: ");
                scanf("%s", maX);
                xoaMatHang(&list, maX);
                break;
            case 8:
                sapXepTheoTen(&list);
                break;
            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 0);
    
    // Giải phóng bộ nhớ trước khi kết thúc chương trình
    xoaDanhSach(&list);
    return 0;
}
