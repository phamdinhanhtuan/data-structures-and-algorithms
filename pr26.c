#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc sinh viên
struct SinhVien {
    char ten[50];
    char maSV[10];
    float diemTB;
    char maLop[10];
    struct SinhVien* next;
};

typedef struct SinhVien* LinkedList;

// 1. Tạo node mới
struct SinhVien* taoNode(char* ten, char* ma, float diem, char* lop) {
    struct SinhVien* newNode = (struct SinhVien*)malloc(sizeof(struct SinhVien));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    strcpy(newNode->ten, ten);
    strcpy(newNode->maSV, ma);
    newNode->diemTB = diem;
    strcpy(newNode->maLop, lop);
    newNode->next = NULL;
    return newNode;
}

// 2. Thêm đầu danh sách
void themDau(LinkedList* list, char* ten, char* ma, float diem, char* lop) {
    struct SinhVien* newNode = taoNode(ten, ma, diem, lop);
    newNode->next = *list;
    *list = newNode;
}

// 3. Thêm cuối danh sách
void themCuoi(LinkedList* list, char* ten, char* ma, float diem, char* lop) {
    struct SinhVien* newNode = taoNode(ten, ma, diem, lop);
    
    if (*list == NULL) {
        *list = newNode;
        return;
    }
    
    struct SinhVien* current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 4. Thêm sau vị trí x
void themSauX(LinkedList* list, char* maX, char* ten, char* ma, float diem, char* lop) {
    struct SinhVien* current = *list;
    while (current != NULL) {
        if (strcmp(current->maSV, maX) == 0) {
            struct SinhVien* newNode = taoNode(ten, ma, diem, lop);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay sinh vien co ma %s\n", maX);
}

// 5. Xóa đầu danh sách
void xoaDau(LinkedList* list) {
    if (*list == NULL) return;
    
    struct SinhVien* temp = *list;
    *list = (*list)->next;
    free(temp);
}

// 6. Xóa cuối danh sách
void xoaCuoi(LinkedList* list) {
    if (*list == NULL) return;
    
    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return;
    }
    
    struct SinhVien* current = *list;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// 7. Sắp xếp theo điểm trung bình
void sapXepTheoDiem(LinkedList* list) {
    if (*list == NULL || (*list)->next == NULL) return;
    
    struct SinhVien* i, *j;
    char tempTen[50], tempMa[10], tempLop[10];
    float tempDiem;
    
    for (i = *list; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->diemTB > j->diemTB) {
                // Hoán đổi thông tin
                strcpy(tempTen, i->ten);
                strcpy(tempMa, i->maSV);
                tempDiem = i->diemTB;
                strcpy(tempLop, i->maLop);
                
                strcpy(i->ten, j->ten);
                strcpy(i->maSV, j->maSV);
                i->diemTB = j->diemTB;
                strcpy(i->maLop, j->maLop);
                
                strcpy(j->ten, tempTen);
                strcpy(j->maSV, tempMa);
                j->diemTB = tempDiem;
                strcpy(j->maLop, tempLop);
            }
        }
    }
}

// 8. Tách danh sách
void tachDanhSach(LinkedList list, LinkedList* list1, LinkedList* list2) {
    *list1 = NULL;
    *list2 = NULL;
    
    while (list != NULL) {
        if (list->diemTB >= 5) {
            themCuoi(list1, list->ten, list->maSV, list->diemTB, list->maLop);
        } else {
            themCuoi(list2, list->ten, list->maSV, list->diemTB, list->maLop);
        }
        list = list->next;
    }
}

// 9. Hiển thị danh sách
void hienThiDS(LinkedList list) {
    printf("\nDanh sach sinh vien:\n");
    printf("%-30s %-10s %-10s %-10s\n", "Ten", "Ma SV", "Diem TB", "Ma Lop");
    printf("----------------------------------------------------\n");
    
    while (list != NULL) {
        printf("%-30s %-10s %-10.2f %-10s\n",
               list->ten, list->maSV, list->diemTB, list->maLop);
        list = list->next;
    }
}

// Main function
int main() {
    LinkedList list = NULL;
    int choice;
    char ten[50], ma[10], lop[10], maX[10];
    float diem;
    
    do {
        printf("\n=== QUAN LY SINH VIEN ===\n");
        printf("1. Them sinh vien dau danh sach\n");
        printf("2. Them sinh vien cuoi danh sach\n");
        printf("3. Them sinh vien sau ma X\n");
        printf("4. Xoa sinh vien dau danh sach\n");
        printf("5. Xoa sinh vien cuoi danh sach\n");
        printf("6. Sap xep theo diem TB\n");
        printf("7. Tach danh sach\n");
        printf("8. Hien thi danh sach\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Nhap ten: "); scanf(" %[^\n]s", ten);
                printf("Nhap ma: "); scanf("%s", ma);
                printf("Nhap diem: "); scanf("%f", &diem);
                printf("Nhap lop: "); scanf("%s", lop);
                themDau(&list, ten, ma, diem, lop);
                break;
            case 2:
                printf("Nhap ten: "); scanf(" %[^\n]s", ten);
                printf("Nhap ma: "); scanf("%s", ma);
                printf("Nhap diem: "); scanf("%f", &diem);
                printf("Nhap lop: "); scanf("%s", lop);
                themCuoi(&list, ten, ma, diem, lop);
                break;
            case 3:
                printf("Nhap ma X: "); scanf("%s", maX);
                printf("Nhap ten: "); scanf(" %[^\n]s", ten);
                printf("Nhap ma: "); scanf("%s", ma);
                printf("Nhap diem: "); scanf("%f", &diem);
                printf("Nhap lop: "); scanf("%s", lop);
                themSauX(&list, maX, ten, ma, diem, lop);
                break;
            case 4:
                xoaDau(&list);
                printf("Da xoa sinh vien dau danh sach!\n");
                break;
            case 5:
                xoaCuoi(&list);
                printf("Da xoa sinh vien cuoi danh sach!\n");
                break;
            case 6:
                sapXepTheoDiem(&list);
                printf("Da sap xep danh sach theo diem!\n");
                break;
            case 7:
                {
                    LinkedList list1, list2;
                    tachDanhSach(list, &list1, &list2);
                    printf("\nDanh sach sinh vien co diem >= 5:\n");
                    hienThiDS(list1);
                    printf("\nDanh sach sinh vien co diem < 5:\n");
                    hienThiDS(list2);
                }
                break;
            case 8:
                hienThiDS(list);
                break;
        }
    } while (choice != 0);
    
    return 0;
}
