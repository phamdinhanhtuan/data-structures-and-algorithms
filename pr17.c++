#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 0

void nhap (int *n) {
	do {
		printf ("Nhap n ( n > 0 ) : ") ;
		scanf ("%d",n) ;
	} while (*n <= 0) ;
}

void cpd (int **ptr , int n) {
	*ptr = (int*)calloc (n ,sizeof (int)) ;

	if (*ptr == NULL) {
		exit (1) ;
	}
}

void nhapmang (int *a , int n) {
	srand (time (NULL)) ;
	for (int i = 0 ; i < n ;i++) {
		a[i] = rand () % (MAX - MIN + 1) + MIN ;
	}
}

void xuatmang (int *a , int n) {
	for (int i = 0 ; i < n ; i++) {
		printf ("%d " , a[i]) ;
	}
}

void sapxep (int *a , int n) {
	for (int i = 0 ; i < n ;i++) {
		for (int j = 0 ; j < n - i - 1 ; j++) {
			if (a[j] < a[j+1]) {
				int tmp = a[j] ;
				a[j] = a[j+1] ;
				a[j+1] = tmp ;
			}
		}
	}
}

int timvitri_nhiphan (int *a , int l , int r , int x) {
	if ( l > r ) return -1 ;

	int m = ( l + r ) / 2 ;

	if (a[m] == x) return m ;
	
	if (a[m] > x) return timvitri_nhiphan(a,l,m-1,x) ;

	return timvitri_nhiphan (a,m+1,r,x) ;
}

void xoaphantux (int *a , int *n , int x) {
	int p = timvitri_nhiphan (a,0,*n-1,x) ;
	if (p == -1) {
		printf ("Khong ton tai gia tri x de xoa !\n") ;
		return ;
	}
	
	for (int i = p ; i < *n - 1 ; i++) {
		a[i] = a[i+1] ;
	}
	(*n)-- ;
}

int main () {
	int choice , *ptr = NULL , n; 

	do {
		printf ("\n===================MENU===================\n") ;
		printf ("1.Sinh so ngau nhien !\n") ;
		printf ("2.Xuat day so ra man hinh !\n") ;
		printf ("3.Sap xep day so giam dan !\n") ;
		printf ("4.Tim vi tri phan tu co gia tri x bang tim kim nhiphan !\n") ;
		printf ("5.Xoa phan tu co gia tri x !\n") ;
		printf ("0.Thoat !\n") ;
		printf ("===================MENU===================\n") ;
		
		printf ("Nhap lua chon : ") ;
		scanf ("%d",&choice) ;
		
		switch (choice) {
		case 1 : 
			printf ("Ban da chon 1 !\n") ;
			nhap (&n) ;
			cpd (&ptr,n) ;
			nhapmang (ptr,n) ;
			break ;
		case 2 : 
			if (ptr == NULL) {
				printf ("Ban chua khoi tao mang , vui long chon 1 !\n") ;
			} else {
				printf ("Mang ban dau : ") ;
				xuatmang (ptr,n) ;	
			}
			break ;
		case 3 : 
			if (ptr == NULL) {
				printf ("Ban chua khoi tao mang , vui long chon 1 !\n") ;
			} else {
				sapxep (ptr,n) ;
				printf ("\nMang sau khi sap xep :") ;
				xuatmang (ptr,n) ;
			}
			break ;
		case 4 : 
			if (ptr == NULL) {
				printf ("Ban chua khoi tao mang , vui long chon 1 !\n") ;
			} else {
				int x ;
				printf ("\nNhap phan tu can tim theo tim kiem nhi phan : ") ;
				scanf ("%d",&x) ;
				int caud = timvitri_nhiphan (ptr,0,n-1,x) ;
				if (caud == -1) {
					printf ("Khong ton tai vi tri phan tu co gia x theo nhiphan !\n") ;
				} else {
					printf ("Phan tu co gia tri can tim tai vi tri : %d\n",caud) ;
				}	
			}
			break ;
		case 5 : 
			if (ptr == NULL) {
				printf ("Ban chua khoi tao mang , vui long chon 1 !\n") ;
			} else {
				int x;
        		printf("Nhap phan tu can xoa: ");
        		scanf("%d", &x);
				xoaphantux (ptr,&n,x) ;	
				printf ("Mang sau khi xoa phan tu : ") ;
				xuatmang (ptr,n) ;
}
			break ;
		case 6 : 
			printf ("Thoat => Nhan 0") ;
			free (ptr) ;
			break ;
		default : 
			printf ("Lua chon khong hop le !") ; 
		}
	} while (choice != 0) ;

	return EXIT_SUCCESS ;
}
