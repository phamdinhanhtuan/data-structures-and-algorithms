#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct danhSachHangHoa {
	int maHang, soLuongTon; 
	char *tenHangHoa;
} hangHoa; 

typedef struct nodeDanhSachHangHoa {
	hangHoa duLieu; 
	struct nodeDanhSachHangHoa *tiepTheo; 
} node; 

void nhapHangHoa(hangHoa *h) {
	int tmp, tmp1;
	do {
		printf("Nhap ma hang: ");
		tmp = scanf("%d", &h->maHang);
		while (getchar() != '\n');

		if (tmp != 1) {
			printf("Vui long nhap so hop le!\n");
		} else if (h->maHang <= 0) {
			printf("Vui long nhap so duong!\n");
		}
	} while (tmp != 1 || (h->maHang) <= 0);

	do {
		printf("Nhap so luong ton kho: ");
		tmp1 = scanf("%d", &h->soLuongTon);
		while (getchar() != '\n');

		if (tmp1 != 1) {
			printf("Vui long nhap so hop le!\n");
		} else if (h->soLuongTon <= 0) {
			printf("Vui long nhap so duong!\n");
		}
	} while (tmp1 != 1 || (h->soLuongTon) <= 0);

	h->tenHangHoa = (char*)malloc(30 * sizeof(char));
	if (h->tenHangHoa == NULL) {
		exit(EXIT_FAILURE);
	}
	printf("Nhap ten day du cua hang hoa: ");
	fgets(h->tenHangHoa, 30, stdin);
	h->tenHangHoa[strcspn(h->tenHangHoa, "\n")] = '\0';
}

void inHangHoa(hangHoa h) {
	printf("\nMa hang da nhap: %d", h.maHang);
	printf("\nSo luong ton kho da nhap: %d", h.soLuongTon);
	printf("\nTen hang hoa da nhap: %s", h.tenHangHoa);
}

void nhapSoLuong(int *n) {
	int tmp;
	do {
		printf("Vui long nhap so luong: ");
		tmp = scanf("%d", n);
		while (getchar() != '\n');

		if (tmp != 1) {
			printf("Vui long nhap so hop le!\n");
		} else if (*n <= 0) {
			printf("Vui long nhap so duong!\n");
		}
	} while (tmp != 1 || *n <= 0);
}

node *taoNode(hangHoa x) {
	node *nodeMoi = (node*)malloc(sizeof(node));
	if (nodeMoi == NULL) {
		exit(EXIT_FAILURE);
	}

	nodeMoi->duLieu.maHang = x.maHang;
	nodeMoi->duLieu.soLuongTon = x.soLuongTon;

	nodeMoi->duLieu.tenHangHoa = (char*)malloc(30 * sizeof(char));
	if (nodeMoi->duLieu.tenHangHoa == NULL) {
		exit(EXIT_FAILURE);
	}
	strcpy(nodeMoi->duLieu.tenHangHoa, x.tenHangHoa);

	nodeMoi->tiepTheo = NULL;

	return nodeMoi;
}

void themSau(node **dau, hangHoa x) {
	node *nodeMoi = taoNode(x);
	if (*dau == NULL) {
		*dau = nodeMoi;
		return;
	}

	node *tmp = *dau;
	while (tmp->tiepTheo != NULL) {
		tmp = tmp->tiepTheo;
	}

	tmp->tiepTheo = nodeMoi;
}

void nhapDanhSachLienKet(node **dau, int n) {
	hangHoa giaTri;
	for (int i = 0; i < n; i++) {
		printf("Nhap gia tri tai vi tri %d: ", i + 1);
		nhapHangHoa(&giaTri);
		themSau(dau, giaTri);
	}
}

void inDanhSachLienKet(node *dau) {
	if (dau == NULL) {
		printf("\nDanh sach lien ket rong!");
		return;
	}

	while (dau != NULL) {
		inHangHoa(dau->duLieu);
		dau = dau->tiepTheo;
	}
}

void timKiemTheoMaHang(node *dau) {
	int giaTri, f = 0, tmp1;
	do {
		printf("\nNhap ma hang can tim kiem: ");
		tmp1 = scanf("%d", &giaTri);
		while (getchar() != '\n');

		if (tmp1 != 1) {
			printf("Vui long nhap so hop le!\n");
		} else if (tmp1 <= 0) {
			printf("Vui long nhap so duong!\n");
		}
	} while (tmp1 != 1 || tmp1 <= 0);

	node *tmp = dau;
	while (tmp != NULL) {
		if (tmp->duLieu.maHang == giaTri) {
			inHangHoa(tmp->duLieu);
			f = 1;
		}
		tmp = tmp->tiepTheo;
	}

	if (!f) {
		printf("Khong tim thay hang hoa co ma hang X!\n");
	}
}

void themHangSauMaHangX(node **dau) {
	int giaTri, f = 0, tmp1;
	hangHoa x;
	do {
		printf("\nNhap ma hang de them vao sau: ");
		tmp1 = scanf("%d", &giaTri);
		while (getchar() != '\n');

		if (tmp1 != 1) {
			printf("Vui long nhap so hop le!\n");
		} else if (tmp1 <= 0) {
			printf("Vui long nhap so duong!\n");
		}
	} while (tmp1 != 1 || tmp1 <= 0);

	node *tmp = *dau;
	while (tmp != NULL) {
		if (tmp->duLieu.maHang == giaTri) {
			f = 1;
			nhapHangHoa(&x);
			node *nodeMoi = taoNode(x);
			nodeMoi->tiepTheo = tmp->tiepTheo;
			tmp->tiepTheo = nodeMoi;
			tmp = nodeMoi->tiepTheo;
		} else {
			tmp = tmp->tiepTheo;
		}
	}

	if (!f) {
		printf("Khong tim thay ma hang X de them vao sau!\n");
	}
}

void xoaDauDanhSach(node **dau) {
	if (*dau == NULL) return;

	node *tmp = *dau;
	*dau = tmp->tiepTheo;
	free(tmp->duLieu.tenHangHoa);
	free(tmp);
}

void xoaToanBoDanhSach(node **dau) {
	char xacNhan;
	do {
		printf("\nBan co chac chan muon xoa toan bo danh sach? Y hoac N?: ");
		scanf(" %c", &xacNhan);
		while (getchar() != '\n');
		if (xacNhan != 'Y' && xacNhan != 'N') {
			printf("Nhap khong hop le! Vui long nhap Y hoac N\n");
		}
	} while (xacNhan != 'Y' && xacNhan != 'N');

	if (xacNhan == 'Y') {
		node *tmp = *dau, *tiepTheo;
		while (tmp != NULL) {
			tiepTheo = tmp->tiepTheo;
			free(tmp->duLieu.tenHangHoa);
			free(tmp);
			tmp = tiepTheo;
		}
		*dau = NULL;
		printf("=>>> Da xoa toan bo danh sach!\n");
	} else {
		printf("=>>> Da huy viec xoa danh sach!\n");
	}
}

void xoaHangTheoMa(node **dau) {
	int x, f = 0;
	printf("\nNhap ma hang can xoa: ");
	scanf("%d", &x);
	while (getchar() != '\n');

	if (*dau == NULL) {
		printf("Danh sach rong!\n");
		return;
	}

	node *tmp = *dau, *truoc = NULL;
	while (tmp != NULL) {
		if (tmp->duLieu.maHang == x) {
			f = 1;
			if (tmp == *dau) {
				*dau = tmp->tiepTheo;
				free(tmp->duLieu.tenHangHoa);
				free(tmp);
			} else {
				truoc->tiepTheo = tmp->tiepTheo;
				free(tmp->duLieu.tenHangHoa);
				free(tmp);
			}
		} else {
			truoc = tmp;
			tmp = tmp->tiepTheo;
		}
	}

	if (!f) {
		printf("Khong tim thay hang hoa co ma can xoa!\n");
	}
}

void giaiPhongDanhSach(node **dau) {
	node *tmp = *dau, *tiepTheo;
	while (tmp != NULL) {
		tiepTheo = tmp->tiepTheo;
		free(tmp->duLieu.tenHangHoa);
		free(tmp);
		tmp = tiepTheo;
	}
	*dau = NULL;
}

void hoanDoi(node *a, node *b) {
	hangHoa tmp = a->duLieu;
	a->duLieu = b->duLieu;
	b->duLieu = tmp;
}

void sapXepDanhSachTang(node **dau, int n) {
	if (*dau == NULL) {
		printf("Danh sach rong!\n");
		return;
	}

	for (node *i = *dau; i != NULL; i = i->tiepTheo) {
		node *min = i;
		for (node *j = i->tiepTheo; j != NULL; j = j->tiepTheo) {
			if (strcmp(min->duLieu.tenHangHoa, j->duLieu.tenHangHoa) > 0) {
				min = j;
			}
		}
		hoanDoi(i, min);
	}
}

int demNode(node *dau) {
	int dem = 0;

	while (dau != NULL) {
		dem++;
		dau = dau->tiepTheo;
	}

	return dem;
}

void giaTriTaiViTriK(node *dau) {
	int viTri, tmp1, chiSo = 0;
	do {
		printf("\nNhap vi tri can in gia tri: ");
		tmp1 = scanf("%d", &viTri);

		if (tmp1 != 1 || viTri <= 0) {
			printf("So khong hop le!\n");
		}
	} while (tmp1 != 1 || viTri <= 0);

	node *tmp = dau;
	while (tmp != NULL && chiSo < viTri - 1) {
		chiSo++;
		tmp = tmp->tiepTheo;
	}

	if (tmp == NULL) {
		printf("\nVi tri khong hop le");
		return;
	}

	printf("Du lieu cua phan tu tai vi tri %d la: ", viTri);
	inHangHoa(tmp->duLieu);
}

node* timPhanTuLonNhat(node *dau) {
	node *maxDauTien = dau->tiepTheo;
	node *tmp = dau->tiepTheo;

	while (tmp != NULL) {
		if (tmp > maxDauTien) {
			maxDauTien = tmp;
		}
		tmp = tmp->tiepTheo;
	}

	return maxDauTien;
}

int main() {
	int n;
	node *dau = NULL;

	nhapSoLuong(&n);

	nhapDanhSachLienKet(&dau, n);

	printf("========Danh sach hang hoa da nhap========: ");
	inDanhSachLienKet(dau);

	printf("\nTim kiem hang hoa theo ma hang X: ");
	timKiemTheoMaHang(dau);

	themHangSauMaHangX(&dau);
	printf("\n========Danh sach da cap nhat (them sau)========: ");
	inDanhSachLienKet(dau);

	xoaDauDanhSach(&dau);
	printf("\n========Danh sach da cap nhat (xoa dau)========: ");
	inDanhSachLienKet(dau);

	xoaToanBoDanhSach(&dau);
	printf("\n========Danh sach da cap nhat (xoa toan bo)========: ");
	inDanhSachLienKet(dau);

	xoaHangTheoMa(&dau);
	printf("\n========Danh sach da cap nhat (da xoa hang)========: ");
	inDanhSachLienKet(dau);

	sapXepDanhSachTang(&dau, n);
	printf("\n========Danh sach da cap nhat (da sap xep)========: ");
	inDanhSachLienKet(dau);

	printf("\nSo luong node trong danh sach lien ket: %d", demNode(dau));

	giaTriTaiViTriK(dau);

	printf("\nPhan tu lon nhat: ");
	timPhanTuLonNhat(dau);

	if (dau != NULL) {
		giaiPhongDanhSach(&dau);
	}

	return EXIT_SUCCESS;
} 
