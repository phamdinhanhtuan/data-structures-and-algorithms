#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int roomId, status;
	char *roomName;
} phong;

typedef struct node {
	phong data;
	struct node *next;
} node;

void xoaBoDem() {
	while (getchar() != '\n');
}

void thoat() {
	exit(EXIT_FAILURE);
}

node *taoNode(phong val) {
	node *nodeNew = (node*)malloc(sizeof(node));
	if (nodeNew == NULL) thoat();

	nodeNew->data.roomId = val.roomId;
	nodeNew->data.status = val.status;

	nodeNew->data.roomName = (char*)malloc(30 * sizeof(char));
	if (nodeNew->data.roomName == NULL) thoat();
	strcpy(nodeNew->data.roomName, val.roomName);

	nodeNew->next = NULL;

	return nodeNew;
}

void themVaoCuoi(node **head, phong val) {
	if (*head == NULL) {
		*head = taoNode(val);
		return;
	}

	node *tmp = *head, *nodeNew = taoNode(val);
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = nodeNew;
}

void nhapPhong(phong *r) {
	while (1) {
		printf("Vui lòng nhập mã phòng: ");
		if ((scanf("%d", &r->roomId)) == 1 && r->roomId >= 0) {
			break;
		}
		printf("Vui lòng nhập mã phòng hợp lệ!\n");
		xoaBoDem();
	}
	xoaBoDem();

	while (1) {
		printf("Vui lòng nhập trạng thái (1: đã đặt || 0: còn trống): ");
		if ((scanf("%d", &r->status)) == 1 && (r->status == 1 || r->status == 0)) {
			break;
		}
		printf("Vui lòng nhập trạng thái hợp lệ (0 hoặc 1)!\n");
		xoaBoDem();
	}
	xoaBoDem();

	printf("Vui lòng nhập tên phòng: ");
	r->roomName = (char*)malloc(30 * sizeof(char));
	if (r->roomName == NULL) thoat();
	fgets(r->roomName, 30, stdin);
	r->roomName[strcspn(r->roomName, "\n")] = '\0';
}

void inPhong(phong *r) {
	printf("Mã phòng đã nhập: %d\n", r->roomId);
	printf("Tên phòng đã nhập: %s\n", r->roomName);
	printf("Trạng thái đã nhập: %s\n", r->status == 1 ? "đã đặt" : "còn trống");
}

void nhapSoLuong(int *n) {
	while (1) {
		printf("Vui lòng nhập số lượng: ");
		if ((scanf("%d", n)) == 1 && *n >= 0) {
			break;
		}
		printf("Vui lòng nhập số hợp lệ!\n");
		xoaBoDem();
	}
}

void nhapDanhSach(node **head, int n) {
	phong val;
	for (int i = 0; i < n; i++) {
		printf("Vui lòng nhập thông tin phòng thứ %d!\n", i);
		nhapPhong(&val);
		themVaoCuoi(head, val);
		free(val.roomName);
	}
}

void inDanhSach(node *head) {
	while (head != NULL) {
		inPhong(&head->data);
		head = head->next;
	}
}

void inPhongTrong(node *head) {
	int f = 0;
	node *tmp = head;
	while (tmp != NULL) {
		if (tmp->data.status == 0) {
			printf("Tên phòng còn trống: %s\n", tmp->data.roomName);
			f = 1;
		}
		tmp = tmp->next;
	}

	if (!f) {
		printf("Không có phòng trống!\n");
	}
}

void hoanDoi(phong *a, phong *b) {
	phong tmp = *a;
	*a = *b;
	*b = tmp;
}

void sapXepTheoMaPhong(node **head) {
	for (node *i = *head; i != NULL; i = i->next) {
		node *min = i;
		for (node *j = i->next; j != NULL; j = j->next) {
			if (j->data.roomId < min->data.roomId) {
				min = j;
			}
		}
		hoanDoi(&min->data, &i->data);
	}
}

node* timPhongDaDat(node *head) {
	node *tmp = head;
	while (tmp != NULL) {
		if (tmp->data.status == 1) {
			return tmp;
		}
		tmp = tmp->next;
	}

	return NULL;
}

void giaiPhongDanhSach(node **head) {
	node *tmp = *head;
	while (tmp != NULL) {
		node *next = tmp->next;
		free(tmp->data.roomName);
		free(tmp);
		tmp = next;
	}
	*head = NULL;
}

int main() {
	node *head = NULL;
	int luaChon, n;

	do {
		printf("=====================MENU=====================");
		printf("\n1. Nhập danh sách phòng!");
		printf("\n2. In danh sách phòng!");
		printf("\n3. In tên phòng còn trống!");
		printf("\n4. Sắp xếp tăng dần theo mã phòng!");
		printf("\n5. Tìm phòng đã đặt đầu tiên!");
		printf("\n0. Thoát!");
		printf("\n=====================MENU=====================\n");

		while (1) {
			printf("Vui lòng nhập lựa chọn của bạn: ");
			if ((scanf("%d", &luaChon)) == 1 && luaChon >= 0) {
				break;
			}
			printf("Vui lòng nhập lựa chọn hợp lệ!\n");
			xoaBoDem();
		}

		switch (luaChon) {
			case 1:
				printf("Bạn đã chọn 1!\n");
				giaiPhongDanhSach(&head);
				nhapSoLuong(&n);
				nhapDanhSach(&head, n);
				break;
			case 2:
				printf("Bạn đã chọn 2!\n");
				if (head == NULL) {
					printf("Danh sách đang trống!\nVui lòng chọn mục 1 trước!\n");
				} else {
					inDanhSach(head);
				}
				break;
			case 3:
				printf("Bạn đã chọn 3!\n");
				if (head == NULL) {
					printf("Danh sách đang trống!\nVui lòng chọn mục 1 trước!\n");
				} else {
					inPhongTrong(head);
				}
				break;
			case 4:
				printf("Bạn đã chọn 4!\n");
				if (head == NULL) {
					printf("Danh sách đang trống!\nVui lòng chọn mục 1 trước!\n");
				} else {
					printf("Danh sách trước khi sắp xếp!\n");
					inDanhSach(head);
					printf("Danh sách sau khi sắp xếp!\n");
					sapXepTheoMaPhong(&head);
					inDanhSach(head);
				}
				break;
			case 5:
				printf("Bạn đã chọn 5!\n");
				if (head == NULL) {
					printf("Danh sách đang trống!\nVui lòng chọn mục 1 trước!\n");
				} else {
					node *timThay = timPhongDaDat(head);
					if (timThay) {
						printf("Phòng đầu tiên: ");
						inPhong(&timThay->data);
					} else {
						printf("Không tìm thấy phòng đã đặt!\n");
					}
				}
				break;
			case 0:
				printf("Bạn đã chọn 0!\n");
				printf("Đang thoát chương trình........!\n");
				giaiPhongDanhSach(&head);
				break;
			default:
				printf("Vui lòng chỉ nhập từ 0 đến 5!\n");
		}
	} while (luaChon != 0);

	return EXIT_SUCCESS;
}
