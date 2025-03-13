#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút cho danh sách liên kết đôi
typedef struct node {
    int info;           // Dữ liệu của nút
    struct node *pre;   // Con trỏ trỏ đến nút trước đó
    struct node *next;  // Con trỏ trỏ đến nút tiếp theo
} Node;

// Khởi tạo danh sách liên kết đôi
void init(Node **phead) {
    *phead = NULL;  // Đặt con trỏ đầu danh sách thành NULL
}

// Kiểm tra danh sách có rỗng hay không
int isEmpty(Node *phead) {
    return phead == NULL;  // Trả về 1 nếu danh sách rỗng, ngược lại trả về 0
}

// Tạo một node mới có dữ liệu x
Node* createNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));  // Cấp phát bộ nhớ cho nút mới
    newNode->info = x;  // Gán giá trị x cho nút mới
    newNode->pre = NULL;  // Đặt con trỏ pre của nút mới thành NULL
    newNode->next = NULL;  // Đặt con trỏ next của nút mới thành NULL
    return newNode;  // Trả về con trỏ đến nút mới
}

// Thêm phần tử mới vào đầu danh sách
void insertFirst(Node **phead, int x) {
    Node *newNode = createNode(x);  // Tạo nút mới với giá trị x
    if (*phead != NULL) {
        (*phead)->pre = newNode;  // Cập nhật con trỏ pre của nút đầu tiên hiện tại
    }
    newNode->next = *phead;  // Đặt con trỏ next của nút mới trỏ đến đầu danh sách hiện tại
    *phead = newNode;  // Cập nhật đầu danh sách để trỏ đến nút mới
}

// Nhập danh sách
void inputList(Node **phead) {
    int n, x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);  // Nhập số lượng phần tử
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);  // Nhập giá trị của phần tử
        insertFirst(phead, x);  // Thêm phần tử vào đầu danh sách
    }
}

// Xuất danh sách ra màn hình
void outputList(Node *phead) {
    Node *current = phead;  // Bắt đầu từ đầu danh sách
    while (current != NULL) {
        printf("%d ", current->info);  // In giá trị của nút hiện tại
        current = current->next;  // Di chuyển đến nút tiếp theo
    }
    printf("\n");
}

// Sắp xếp danh sách tăng dần
void sort(Node *phead) {
    Node *i, *j;
    int temp;
    for (i = phead; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {  // Nếu giá trị của nút i lớn hơn nút j
                temp = i->info;  // Hoán đổi giá trị của hai nút
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

// Tìm phần tử có giá trị z và thêm một phần tử mới vào sau z
void insertAfterZ(Node **phead, int z, int newValue) {
    Node *current = *phead;  // Bắt đầu từ đầu danh sách
    while (current != NULL) {
        if (current->info == z) {  // Nếu tìm thấy nút có giá trị z
            Node *newNode = createNode(newValue);  // Tạo nút mới với giá trị newValue
            newNode->next = current->next;  // Đặt con trỏ next của nút mới trỏ đến nút sau z
            if (current->next != NULL) {
                current->next->pre = newNode;  // Cập nhật con trỏ pre của nút sau z
            }
            newNode->pre = current;  // Đặt con trỏ pre của nút mới trỏ đến z
            current->next = newNode;  // Đặt con trỏ next của z trỏ đến nút mới
            return;
        }
        current = current->next;  // Di chuyển đến nút tiếp theo
    }
    printf("Khong tim thay phan tu co gia tri %d\n", z);  // Thông báo nếu không tìm thấy z
}

// Xóa phần tử đầu danh sách
void deleteFirst(Node **phead) {
    if (*phead == NULL) return;  // Nếu danh sách rỗng, không làm gì
    Node *temp = *phead;  // Lưu lại nút đầu tiên
    *phead = (*phead)->next;  // Cập nhật đầu danh sách để trỏ đến nút thứ hai
    if (*phead != NULL) {
        (*phead)->pre = NULL;  // Cập nhật con trỏ pre của nút mới đầu tiên
    }
    free(temp);  // Giải phóng bộ nhớ của nút đầu tiên
}

// Xóa phần tử có giá trị z
void deleteElement(Node **phead, int z) {
    Node *current = *phead;  // Bắt đầu từ đầu danh sách
    while (current != NULL) {
        if (current->info == z) {  // Nếu tìm thấy nút có giá trị z
            if (current->pre != NULL) {
                current->pre->next = current->next;  // Cập nhật con trỏ next của nút trước z
            } else {
                *phead = current->next;  // Nếu z là nút đầu tiên, cập nhật đầu danh sách
            }
            if (current->next != NULL) {
                current->next->pre = current->pre;  // Cập nhật con trỏ pre của nút sau z
            }
            free(current);  // Giải phóng bộ nhớ của nút cần xóa
            return;
        }
        current = current->next;  // Di chuyển đến nút tiếp theo
    }
    printf("Khong tim thay phan tu co gia tri %d\n", z);  // Thông báo nếu không tìm thấy z
}

// Xóa toàn bộ danh sách
void deleteAll(Node **phead) {
    Node *current = *phead;  // Bắt đầu từ đầu danh sách
    Node *next;
    while (current != NULL) {
        next = current->next;  // Lưu lại nút tiếp theo
        free(current);  // Giải phóng bộ nhớ của nút hiện tại
        current = next;  // Di chuyển đến nút tiếp theo
    }
    *phead = NULL;  // Đặt đầu danh sách thành NULL
}

// Đếm số nút trên danh sách
int count(Node *phead) {
    int count = 0;
    Node *current = phead;  // Bắt đầu từ đầu danh sách
    while (current != NULL) {
        count++;  // Tăng biến đếm
        current = current->next;  // Di chuyển đến nút tiếp theo
    }
    return count;  // Trả về số lượng nút
}

// Trả về giá trị của node thứ k trong danh sách
int valueAt(Node *phead, int k) {
    Node *current = phead;  // Bắt đầu từ đầu danh sách
    int index = 0;
    while (current != NULL) {
        if (index == k) {  // Nếu đã đến nút thứ k
            return current->info;  // Trả về giá trị của nút
        }
        index++;  // Tăng chỉ số
        current = current->next;  // Di chuyển đến nút tiếp theo
    }
    printf("Khong tim thay node thu %d\n", k);  // Thông báo nếu không tìm thấy nút thứ k
    return -1;  // Trả về -1 nếu không tìm thấy
}

// Tìm phần tử lớn nhất trong danh sách
int max(Node *phead) {
    int maxValue = phead->info;  // Giả sử giá trị lớn nhất là giá trị của nút đầu tiên
    Node *current = phead->next;  // Bắt đầu từ nút thứ hai
    while (current != NULL) {
        if (current->info > maxValue) {  // Nếu tìm thấy giá trị lớn hơn
            maxValue = current->info;  // Cập nhật giá trị lớn nhất
        }
        current = current->next;  // Di chuyển đến nút tiếp theo
    }
    return maxValue;  // Trả về giá trị lớn nhất
}

// Tìm phần tử nhỏ nhất trong danh sách
int min(Node *phead) {
    int minValue = phead->info;  // Giả sử giá trị nhỏ nhất là giá trị của nút đầu tiên
    Node *current = phead->next;  // Bắt đầu từ nút thứ hai
    while (current != NULL) {
        if (current->info < minValue) {  // Nếu tìm thấy giá trị nhỏ hơn
            minValue = current->info;  // Cập nhật giá trị nhỏ nhất
        }
        current = current->next;  // Di chuyển đến nút tiếp theo
    }
    return minValue;  // Trả về giá trị nhỏ nhất
}

int main() {
    Node *head;
    init(&head);

    inputList(&head);
    printf("Danh sach vua nhap: ");
    outputList(head);

    sort(head);
    printf("Danh sach sau khi sap xep: ");
    outputList(head);

    int z = 5, newValue = 10;
    insertAfterZ(&head, z, newValue);
    printf("Danh sach sau khi them phan tu sau %d: ", z);
    outputList(head);

    deleteFirst(&head);
    printf("Danh sach sau khi xoa phan tu dau: ");
    outputList(head);

    deleteElement(&head, z);
    printf("Danh sach sau khi xoa phan tu co gia tri %d: ", z);
    outputList(head);

    printf("So nut trong danh sach: %d\n", count(head));

    int k = 2;
    printf("Gia tri cua node thu %d: %d\n", k, valueAt(head, k));

    printf("Phan tu lon nhat trong danh sach: %d\n", max(head));
    printf("Phan tu nho nhat trong danh sach: %d\n", min(head));

    deleteAll(&head);
    printf("Danh sach sau khi xoa toan bo: ");
    outputList(head);

    return 0;
}
