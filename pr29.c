#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc cho một phòng
typedef struct Room {
    int id;                // Mã phòng
    char type[50];         // Tên loại phòng
    int status;            // Tình trạng phòng (1: Đã có khách, 0: Còn trống)
    struct Room *next;     // Con trỏ đến phòng tiếp theo
} Room;

// Hàm kiểm tra danh sách có rỗng không
int empty(Room *head) {
    return head == NULL;
}

// Hàm đếm số lượng phòng trong danh sách liên kết
int size(Room *head) {
    int count = 0;
    Room *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Hàm tạo một phòng mới
Room* createRoom(int id, char type[], int status) {
    Room *newRoom = (Room*)malloc(sizeof(Room));
    newRoom->id = id;
    strcpy(newRoom->type, type);
    newRoom->status = status;
    newRoom->next = NULL;
    return newRoom;
}

// Hàm thêm phòng vào danh sách liên kết
void addRoom(Room **head, int id, char type[], int status) {
    Room *newRoom = createRoom(id, type, status);
    if (*head == NULL) {
        *head = newRoom;
    } else {
        Room *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }
}

// Hàm xuất danh sách các phòng
void displayRooms(Room *head) {
    printf("\nDanh sach cac phong:\n");
    Room *temp = head;
    while (temp != NULL) {
        printf("Ma phong: %d, Loai phong: %s, Tinh trang: %s\n", temp->id, temp->type, temp->status ? "Da dat" : "Con trong");
        temp = temp->next;
    }
}

// Hàm xuất tên loại phòng của các phòng còn trống
void displayAvailableRoomTypes(Room *head) {
    printf("\nCac loai phong con trong:\n");
    Room *temp = head;
    while (temp != NULL) {
        if (temp->status == 0) {
            printf("Loai phong: %s\n", temp->type);
        }
        temp = temp->next;
    }
}

// Hàm sắp xếp danh sách phòng theo mã phòng bằng thuật toán sắp xếp nổi bọt
void sortRoomsById(Room **head) {
    if (*head == NULL) return;
    int swapped;
    Room *ptr1;
    Room *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->id > ptr1->next->id) {
                int tempId = ptr1->id;
                char tempType[50];
                strcpy(tempType, ptr1->type);
                int tempStatus = ptr1->status;
                
                ptr1->id = ptr1->next->id;
                strcpy(ptr1->type, ptr1->next->type);
                ptr1->status = ptr1->next->status;
                
                ptr1->next->id = tempId;
                strcpy(ptr1->next->type, tempType);
                ptr1->next->status = tempStatus;
                
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Hàm tìm phòng đầu tiên đã có khách đặt
void findFirstBookedRoom(Room *head) {
    Room *temp = head;
    while (temp != NULL) {
        if (temp->status == 1) {
            printf("\nPhong dau tien da co khach dat:\nMa phong: %d, Loai phong: %s\n", temp->id, temp->type);
            return;
        }
        temp = temp->next;
    }
    printf("\nKhong co phong nao da duoc dat.\n");
}

int main() {
    Room *hotel = NULL;
    int choice, id, status;
    char type[50];
    
    do {
        printf("\nMENU:\n");
        printf("1. Nhap vao danh sach cac phong\n");
        printf("2. Xuat danh sach cac phong\n");
        printf("3. Xuat ten loai phong cua cac phong con trong\n");
        printf("4. Sap xep danh sach cac phong tang dan theo ma phong\n");
        printf("5. Tim phong dau tien da co khach dat\n");
        printf("6. Kiem tra danh sach co rong khong\n");
        printf("7. Dem so phong trong danh sach\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); // Loại bỏ ký tự newline
        
        switch (choice) {
            case 1:
                printf("Nhap ma phong: ");
                scanf("%d", &id);
                getchar();
                printf("Nhap loai phong: ");
                fgets(type, sizeof(type), stdin);
                type[strcspn(type, "\n")] = 0;
                printf("Nhap tinh trang (1: Da dat, 0: Con trong): ");
                scanf("%d", &status);
                addRoom(&hotel, id, type, status);
                break;
            case 2:
                displayRooms(hotel);
                break;
            case 3:
                displayAvailableRoomTypes(hotel);
                break;
            case 4:
                sortRoomsById(&hotel);
                printf("\nDa sap xep danh sach phong theo ma phong!\n");
                break;
            case 5:
                findFirstBookedRoom(hotel);
                break;
            case 6:
                printf(empty(hotel) ? "Danh sach rong.\n" : "Danh sach khong rong.\n");
                break;
            case 7:
                printf("So phong hien tai: %d\n", size(hotel));
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    
    return 0;
}
