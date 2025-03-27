#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc mặt hàng
struct MatHang {
    char maHang[10];
    char tenHang[50];
    int soLuong;
    float donGia;
    struct MatHang* next;
};

typedef struct MatHang* LinkedList;

// 1. Tạo node mới
struct MatHang* taoNode(char* ma, char* ten, int sl, float gia) {
    struct MatHang* newNode = (struct MatHang*)malloc(sizeof(struct MatHang));
    strcpy(newNode->maHang, ma);
    strcpy(newNode->tenHang, ten);
    newNode->soLuong = sl;
    newNode->donGia = gia;
    newNode->next = NULL;
    return newNode;
}

// 2. Thêm mặt hàng mới
void themMatHang(LinkedList* list, char* ma, char* ten, int sl, float gia) {
    struct MatHang* newNode = taoNode(ma, ten, sl, gia);
    newNode->next = *list;
    *list = newNode;
}

// 3. Xóa mặt hàng theo mã
void xoaTheoMa(LinkedList* list, char* ma) {
    if (*list == NULL) return;
    
    if (strcmp((*list)->maHang, ma) == 0) {
        struct MatHang* temp = *list;
        *list = (*list)->next;
        free(temp);
        return;
    }
    
    struct MatHang* current = *list;
    while (current->next != NULL) {
        if (strcmp(current->next->maHang, ma) == 0) {
            struct MatHang* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// 4. Tính tổng giá trị
float tinhTongGiaTri(LinkedList list) {
    float tong = 0;
    while (list != NULL) {
        tong += list->soLuong * list->donGia;
        list = list->next;
    }
    return tong;
}

// 5. Tìm mặt hàng có giá trị cao nhất
struct MatHang* timGiaTriCaoNhat(LinkedList list) {
    if (list == NULL) return NULL;
    
    struct MatHang* maxNode = list;
    float maxGiaTri = list->soLuong * list->donGia;
    
    list = list->next;
    while (list != NULL) {
        float giaTri = list->soLuong * list->donGia;
        if (giaTri > maxGiaTri) {
            maxGiaTri = giaTri;
            maxNode = list;
        }
        list = list->next;
    }
    return maxNode;
}

// 6. Sắp xếp theo tên hàng
void sapXepTheoTen(LinkedList* list) {
    if (*list == NULL || (*list)->next == NULL) return;
    
    struct MatHang* i, *j;
    char tempMa[10], tempTen[50];
    int tempSL;
    float tempGia;
    
    for (i = *list; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->tenHang, j->tenHang) > 0) {
                // Hoán đổi thông tin
                strcpy(tempMa, i->maHang);
                strcpy(tempTen, i->tenHang);
                tempSL = i->soLuong;
                tempGia = i->donGia;
                
                strcpy(i->maHang, j->maHang);
                strcpy(i->tenHang, j->tenHang);
                i->soLuong = j->soLuong;
                i->donGia = j->donGia;
                
                strcpy(j->maHang, tempMa);
                strcpy(j->tenHang, tempTen);
                j->soLuong = tempSL;
                j->donGia = tempGia;
            }
        }
    }
}

// 7. Hiển thị danh sách
void hienThiDS(LinkedList list) {
    printf("\nDanh sach mat hang:\n");
    printf("%-10s %-30s %-10s %-15s %-15s\n", 
           "Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
    printf("--------------------------------------------------------\n");
    
    while (list != NULL) {
        printf("%-10s %-30s %-10d %-15.2f %-15.2f\n",
               list->maHang, list->tenHang, list->soLuong, 
               list->donGia, list->soLuong * list->donGia);
        list = list->next;
    }
}

int main() {
    LinkedList list = NULL;
    int choice;
    char ma[10], ten[50];
    int sl;
    float gia;
    
    do {
        printf("\n=== QUAN LY MAT HANG ===\n");
        printf("1. Them mat hang\n");
        printf("2. Xoa mat hang theo ma\n");
        printf("3. Tinh tong gia tri\n");
        printf("4. Tim mat hang gia tri cao nhat\n");
        printf("5. Sap xep theo ten\n");
        printf("6. Hien thi danh sach\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Nhap ma hang: "); scanf("%s", ma);
                printf("Nhap ten hang: "); scanf(" %[^\n]s", ten);
                printf("Nhap so luong: "); scanf("%d", &sl);
                printf("Nhap don gia: "); scanf("%f", &gia);
                themMatHang(&list, ma, ten, sl, gia);
                break;
            case 2:
                printf("Nhap ma hang can xoa: "); scanf("%s", ma);
                xoaTheoMa(&list, ma);
                printf("Da xoa mat hang!\n");
                break;
            case 3:
                printf("Tong gia tri hang hoa: %.2f\n", tinhTongGiaTri(list));
                break;
            case 4:
                {
                    struct MatHang* max = timGiaTriCaoNhat(list);
                    if (max != NULL) {
                        printf("\nMat hang co gia tri cao nhat:\n");
                        printf("Ten: %s\n", max->tenHang);
                        printf("Gia tri: %.2f\n", max->soLuong * max->donGia);
                    }
                }
                break;
            case 5:
                sapXepTheoTen(&list);
                printf("Da sap xep danh sach theo ten!\n");
                break;
            case 6:
                hienThiDS(list);
                break;
        }
    } while (choice != 0);
    
    return 0;
}
