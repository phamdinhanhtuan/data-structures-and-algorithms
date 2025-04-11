#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct danhSachPhongKhachSan {
	int maPhong ; 
	char *tenPhong , *trangThai ; 
} danhSach ; 

typedef struct thongTinMoiPhong {
	danhSach duLieu ; 
	struct thongTinMoiPhong *tiepTheo ; 
} nut ;

void nhapThongTinPhong (danhSach *ds) {
	int tam ; 
	do {
		printf ("Nhap ma phong: ") ;
		tam = scanf ("%d",&ds->maPhong) ;
		while (getchar () != '\n') ;

		if (tam != 1) {
			printf ("Vui long nhap mot so hop le!\n") ;
		} else if (tam <= 0) {
			printf ("Vui long nhap so duong!\n") ;
		}
	} while (tam != 1 || tam <= 0) ;

	printf ("Nhap ten phong: ") ;
	ds->tenPhong = (char*)malloc (30 * sizeof (char)) ;
	if (ds->tenPhong == NULL) {
		exit (EXIT_FAILURE) ;
	}
	fgets (ds->tenPhong , 30 , stdin) ;
	ds->tenPhong[strcspn (ds->tenPhong,"\n")] = '\0' ;

	printf ("Nhap trang thai (trong hoac da dat): ") ;
	ds->trangThai = (char*)malloc (30 * sizeof (char)) ;
	if (ds->trangThai == NULL) {
		exit (EXIT_FAILURE) ;
	}
	fgets (ds->trangThai , 30 , stdin) ;
	ds->trangThai[strcspn (ds->trangThai,"\n")] = '\0' ;
}

void inThongTinPhong (danhSach ds) {
	printf ("\nMa phong: %d" , ds.maPhong) ;
	printf ("\nTen phong: %s" , ds.tenPhong) ;
	printf ("\nTrang thai: %s" , ds.trangThai) ;
}

void nhapSoLuong (int *n) {
	int tam ;
	do {
		printf ("Nhap so luong phong: ") ;
		tam = scanf ("%d",n) ;

		if (tam != 1) {
			printf ("Vui long nhap mot so hop le!\n") ;
		} else if (*n <= 0) {
			printf ("Vui long nhap so duong!\n") ;
		}
	} while (tam != 1 || *n <= 0) ;
}

nut *taoNut (danhSach x) {
	nut *nutMoi = (nut*)malloc (sizeof (nut)) ;
	if (nutMoi == NULL) {
		exit (EXIT_FAILURE) ;
	}

	nutMoi->duLieu.maPhong = x.maPhong ;

	nutMoi->duLieu.tenPhong = (char*)malloc (30 * sizeof (char)) ;
	if (nutMoi->duLieu.tenPhong == NULL) {
		exit (EXIT_FAILURE) ;
	}
	strcpy (nutMoi->duLieu.tenPhong , x.tenPhong) ;

	nutMoi->duLieu.trangThai = (char*)malloc (30 * sizeof (char)) ;
	if (nutMoi->duLieu.trangThai == NULL) {
		exit (EXIT_FAILURE) ;
	}
	strcpy (nutMoi->duLieu.trangThai , x.trangThai) ;

	nutMoi -> tiepTheo = NULL ; 

	return nutMoi ;
}

void themSau (nut **dau , danhSach x) {
	nut *nutMoi = taoNut (x) ;
	if (*dau == NULL) {
		*dau = nutMoi ; 
		return ;
	}

	nut *tam = *dau ; 
	while (tam -> tiepTheo != NULL) {
		tam = tam -> tiepTheo ;
	}

	tam -> tiepTheo = nutMoi ; 
}

void nhapDanhSachLienKet (nut **dau , int n) {
	danhSach giaTri ; 
	for (int i = 0 ; i < n ; i++) {
		printf ("Nhap thong tin phong thu %d:\n" , i + 1) ;
		nhapThongTinPhong (&giaTri) ;
		themSau (dau,giaTri) ;
	}
}

void inDanhSachLienKet (nut *dau) {
	if (dau == NULL) {
		printf ("\nDanh sach phong trong!") ;
		return; 
	}

	while (dau != NULL) {
		inThongTinPhong (dau -> duLieu) ;
		dau = dau -> tiepTheo ; 
	}
}

void phongTrongDauTien (nut *dau) {
    int f = 0 ; 
    nut *tam = dau;
    while (tam != NULL) {
        if (strcmp(tam->duLieu.trangThai,"trong") == 0) {
            f = 1;
            inThongTinPhong(tam->duLieu);
            break;  
        }
        tam = tam->tiepTheo;
    }
    if (!f) {
        printf("Khong co phong trong nao!\n");
    }
}

int demPhongDaDat (nut *dau) {
	int dem = 0 ; 
	while (dau != NULL) {
		if (strcmp(dau->duLieu.trangThai,"da dat")==0) {
			dem++ ;
		}
		dau = dau -> tiepTheo ;
	}
	 return dem ; 
}

void themCuoi (nut **dau) {
    danhSach x;
    printf("\nNhap thong tin phong moi:\n");
    nhapThongTinPhong(&x);

    nut *nutMoi = taoNut(x);
    if (*dau == NULL) {
        *dau = nutMoi;
        return;
    }

    nut *tam = *dau;
    while (tam->tiepTheo != NULL) {
        tam = tam->tiepTheo;
    }

    tam->tiepTheo = nutMoi;
}

void hoanDoi (int *a , int *b) {
	int tam = *a ; 
	*a = *b ; 
	*b = tam ;
}

void sapXepMaPhongTang (nut **dau , int n) {
	if (*dau == NULL) {
		printf ("Danh sach phong trong!") ;
		return  ;
	}

	for (nut *i = *dau ; i != NULL ; i = i -> tiepTheo) {
		nut *min = i ; 
		for (nut *j = i -> tiepTheo ; j != NULL ; j = j -> tiepTheo) {
			if (min->duLieu.maPhong > j->duLieu.maPhong) {
				min = j ; 
			}
		}
		hoanDoi (&(i->duLieu.maPhong),&(min->duLieu.maPhong)) ;
	}
}

void giaiPhongDanhSachLienKet (nut **dau) {
	nut *tam = *dau ; 
	while (tam != NULL) {
		nut *tiepTheo = tam -> tiepTheo ; 
		free (tam->duLieu.tenPhong) ;
		free (tam->duLieu.trangThai) ;
		free (tam) ;
		tam = tiepTheo ;
	}
	*dau = NULL ;
}

int main () {
	int n ; 
	nut *dau = NULL ;

	nhapSoLuong (&n) ;

	nhapDanhSachLienKet (&dau,n) ;

	printf ("\n========Danh sach thong tin cac phong========\n") ;
	inDanhSachLienKet (dau) ;

	printf ("\n========Phong trong dau tien la:========\n") ;
	phongTrongDauTien (dau) ;

	printf("\n========So phong da dat: %d\n", demPhongDaDat(dau));

	printf ("\n========Them phong moi vao cuoi danh sach========\n") ;
	themCuoi (&dau) ;
	inDanhSachLienKet (dau) ;

	printf ("\n========Sap xep phong theo ma phong tang dan========\n") ;
	sapXepMaPhongTang (&dau,n) ;
	inDanhSachLienKet (dau) ;

	giaiPhongDanhSachLienKet (&dau) ;

	return EXIT_SUCCESS ;
}
