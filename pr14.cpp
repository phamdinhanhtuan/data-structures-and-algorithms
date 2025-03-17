#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct qlsv {
	char msv [11] , ht [41] ;
	float luong ; 
} ql ; 

void nhap1sinhvien (ql *q) {
	getchar () ;
	printf("Nhap vao ma sinh vien : ");
	fgets (q->msv , sizeof (q->msv) , stdin) ;
	q->msv [strcspn (q->msv , "\n")] = '\0' ;

	printf("Nhap vao ho ten sinh vien : ");
	fgets (q->ht , sizeof (q->ht) , stdin) ;
	q->ht [strcspn (q->ht , "\n")] = '\0' ;

	printf ("Nhap vao luong sinh vien : ") ;
	scanf ("%f",&q->luong) ;
}

void xuat1sinvien (ql q) {
	printf ("Ma sinh vien la : %s\n",q.msv) ;
	printf ("Ho ten sinh vien la : %s\n",q.ht);
	printf ("Luog cua sinh vien la : %.2f\n",q.luong) ;
}

void cpd (ql **ptr , int n) {
	*ptr = (ql*)calloc (n,sizeof (ql)) ;

	if (*ptr == NULL) {
		exit (EXIT_FAILURE) ;
	}
}

void nhap (int *n) {
	do {
		printf ("Nhap n > 0 : ") ;
		scanf ("%d",n) ;
	} while (*n <= 0) ;
}

void nhapmang (ql *a , int n) {
	for (int i = 0 ; i < n ; i++) {
		printf ("Nhap vao sinh vien thu %d !\n" , i + 1) ;
		nhap1sinhvien (&a[i]) ;
	}
}

void xuatmang (ql *a , int n) {
	for (int i = 0 ; i < n ; i++) {
		xuat1sinvien (a[i]) ;
	}
}

void swap (ql *a , ql *b) {
	ql tmp = *a ; 
	*a = *b ; 
	*b = tmp ;
}

void increaseSalaryByInterchange (ql *a , int n) {
	for (int i = 0 ; i < n - 1 ; i++) {
		for (int j = i + 1 ;j < n ; j++) {
			if (a[i].luong > a[j].luong) {
				swap (&a[i],&a[j]) ;
			}	
		}
	}
}

void decreaseNameByInterchange (ql *a , int n) {
	for (int i = 0 ; i < n - 1 ; i++) {
		for (int j = i + 1 ;j < n ; j++) {
			if (strcmp (a[i].ht,a[j].ht) < 0) {
				swap (&a[i],&a[j]) ;
			}	
		}
	}
}

void decreaseSalaryByBubble (ql *a , int n) {
	for (int i = 0 ; i < n - 1 ;i++) {
		for (int j = 0 ; j < n - i - 1 ; j++) {
			if (a[j].luong < a[j+1].luong) {
				swap (&a[j],&a[j+1]) ;
			}
		}
	}
}

void increaseNameByBubble (ql *a , int n) {
	for (int i = 0 ; i < n - 1 ; i++) {
		for (int j = i + 1 ;j < n ; j++) {
			if (strcmp (a[i].ht,a[j].ht) > 0) {
				swap (&a[i],&a[j]) ;
			}	
		}
	}
}

int main () {
	ql *ptr = NULL ; 
	int n ; 

	nhap (&n) ;

	cpd (&ptr,n) ;

	nhapmang (ptr,n) ;

	xuatmang (ptr,n) ;

	increaseSalaryByInterchange (ptr,n);

	decreaseNameByInterchange (ptr,n) ;

	increaseNameByBubble (ptr,n) ;

	decreaseSalaryByBubble (ptr,n) ;

	free (ptr) ;

	return EXIT_SUCCESS ;
}
