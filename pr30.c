#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc mặt hàng
struct MatHang {
    char maHang[10];
    char tenHang[50];
    int soLuong;
    struct MatHang* next;
};

// Tạo mặt hàng mới
struct MatHang* taoNode(char* ma, char* ten, int sl) {
    struct MatHang* node = (struct MatHang*)malloc(sizeof(struct MatHang));
    strcpy(node->maHang, ma);
    strcpy(node->tenHang, ten);
    node->soLuong = sl;
    node->next = NULL;
    return node;
}

// Kiểm tra danh sách rỗng
int kiemTraRong(struct MatHang* head) {
    return (head == NULL);
}

// Đếm số lượng mặt hàng
int demSoLuong(struct MatHang* head) {
    int count = 0;
    struct MatHang* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Nhập một mặt hàng
void nhapMatHang(struct MatHang** head) {
    char ma[10], ten[50];
    int sl;
    char tiepTuc;
    
    do {
        printf("\nNhap ma hang: ");
        fgets(ma, sizeof(ma), stdin);
        ma[strcspn(ma, "\n")] = 0;  // Xóa ký tự xuống dòng
        
        printf("Nhap ten hang: ");
        fgets(ten, sizeof(ten), stdin);
        ten[strcspn(ten, "\n")] = 0;  // Xóa ký tự xuống dòng
        
        printf("Nhap so luong: ");
        scanf("%d", &sl);
        getchar();
        
        struct MatHang* newNode = taoNode(ma, ten, sl);
        
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct MatHang* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
        printf("Tiep tuc nhap? (y/n): ");
        scanf("%c", &tiepTuc);
        getchar();
        
    } while (tiepTuc == 'y' || tiepTuc == 'Y');
}

// Xuất danh sách
void xuatDanhSach(struct MatHang* head) {
    if (head == NULL) {
        printf("\nDanh sach rong!\n");
        return;
    }
    
    printf("\nDANH SACH MAT HANG:\n");
    printf("%-10s %-30s %-10s\n", "Ma hang", "Ten hang", "So luong");
    printf("----------------------------------------\n");
    
    while (head != NULL) {
        printf("%-10s %-30s %-10d\n", 
            head->maHang, head->tenHang, head->soLuong);
        head = head->next;
    }
}

// Sửa lại hàm tìm kiếm để xử lý input trong chính hàm đó
void timMatHang(struct MatHang* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    
    char ma[10];
    printf("\nNhap ma can tim: ");
    scanf("%s", ma);
    getchar();  // Xử lý buffer ngay tại đây
    
    struct MatHang* current = head;
    while (current != NULL) {
        if (strcmp(current->maHang, ma) == 0) {
            printf("Tim thay mat hang:\n");
            printf("Ma hang: %s\n", current->maHang);
            printf("Ten hang: %s\n", current->tenHang);
            printf("So luong: %d\n", current->soLuong);
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay mat hang!\n");
}

// Xóa node đầu
void xoaDau(struct MatHang** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    struct MatHang* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Da xoa mat hang dau!\n");
}

// Xóa theo mã
void xoaTheoMa(struct MatHang** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    
    char ma[10];
    printf("\nNhap ma can xoa: ");
    scanf("%s", ma);
    getchar();  // Xử lý buffer ngay tại đây
    
    if (strcmp((*head)->maHang, ma) == 0) {
        xoaDau(head);
        printf("Da xoa mat hang!\n");
        return;
    }
    
    struct MatHang *prev = *head;
    struct MatHang *curr = (*head)->next;
    
    while (curr != NULL && strcmp(curr->maHang, ma) != 0) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
        printf("Da xoa mat hang!\n");
    } else {
        printf("Khong tim thay mat hang!\n");
    }
}

// Thêm sau mã x
void themSauMa(struct MatHang** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    
    char maX[10], ma[10], ten[50];
    int sl;
    
    printf("\nNhap ma mat hang can them sau: ");
    scanf("%s", maX);
    getchar();  // Xử lý buffer ngay tại đây
    
    struct MatHang* current = *head;
    while (current != NULL && strcmp(current->maHang, maX) != 0) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Khong tim thay mat hang co ma %s!\n", maX);
        return;
    }
    
    printf("\nNhap thong tin mat hang moi:\n");
    printf("Nhap ma hang: ");
    scanf("%s", ma);
    getchar();  // Xử lý buffer ngay tại đây
    
    printf("Nhap ten hang: ");
    scanf("%[^\n]s", ten);
    getchar();
    
    printf("Nhap so luong: ");
    scanf("%d", &sl);
    getchar();
    
    struct MatHang* newNode = taoNode(ma, ten, sl);
    newNode->next = current->next;
    current->next = newNode;
    
    printf("Da them mat hang moi!\n");
}

// Sắp xếp theo tên
void sapXepTheoTen(struct MatHang** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    struct MatHang *i, *j;
    char tempMa[10], tempTen[50];
    int tempSL;
    
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->tenHang, j->tenHang) > 0) {
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
}

// Thêm hàm này vào trước main
void giaiPhongBoNho(struct MatHang** head) {
    struct MatHang* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Sửa lại hàm main với đầy đủ chức năng
int main() {
    struct MatHang* danhSach = NULL;
    int luaChon;
    
    do {
        printf("\n=== MENU QUAN LY MAT HANG ===\n");
        printf("1. Nhap mat hang\n");
        printf("2. Xuat danh sach\n");
        printf("3. Tim mat hang\n");
        printf("4. Them mat hang sau ma x\n");
        printf("5. Xoa mat hang dau\n");
        printf("6. Xoa mat hang theo ma\n");
        printf("7. Sap xep theo ten\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        
        scanf("%d", &luaChon);
        getchar();
        
        switch(luaChon) {
            case 1:
                nhapMatHang(&danhSach);
                break;
            case 2:
                xuatDanhSach(danhSach);
                break;
            case 3:
                timMatHang(danhSach);
                break;
            case 4:
                themSauMa(&danhSach);
                break;
            case 5:
                xoaDau(&danhSach);
                break;
            case 6:
                xoaTheoMa(&danhSach);
                break;
            case 7:
                sapXepTheoTen(&danhSach);
                xuatDanhSach(danhSach);
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(luaChon != 0);
    
    giaiPhongBoNho(&danhSach);
    return 0;
}
