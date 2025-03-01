#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100
#define MIN 0

void nhapsl (int *n) {
 	do {
 		printf ("Nhap vao so luong phan tu : ") ;
 		scanf ("%d",n) ;
 	} while ( *n < 0 ) ;
}

void capphatdong (int **ptr , int n) {
	*ptr = (int*)calloc (n , sizeof (int)) ;

	if ( *ptr == NULL ) {
		printf ("ERR") ;
		exit (1) ;
	}
}

void nhapmang (int *a , int n) {
	srand (time (NULL)) ;
	for (int i = 0 ; i < n ; i++) {
		a[i] = rand () % (MAX - MIN + 1) + MIN ;
	}
}

void xuatmang (int *a , int n) {
	for (int i = 0 ; i < n ; i++) {
		printf ("%d " , *(a+i)) ;
	}
}

void swap (int *a , int *b) {
	int tmp = *a ; 
	*a = *b ; 
	*b = tmp ;
}

void selectionIncrease(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void selectionDecrease(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[min]) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void insertionIncrease(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i] , pos = i - 1;
        while (pos >= 0 && key < a[pos]) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = key;
    }
}

void insertionDecrease(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i] , pos = i - 1;
        while (pos >= 0 && key > a[pos]) {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = key;
    }
}

int main () {
	int n , *ptr ;
 	nhapsl (&n) ;

 	capphatdong (&ptr,n) ;

 	nhapmang (ptr,n) ;

 	xuatmang (ptr,n) ;

 	printf ("\nSelection tang dan :") ;
 	selectionIncrease (ptr,n) ;
 	xuatmang (ptr,n) ;

 	printf ("\nSelection giam dan : ") ;
 	selectionDecrease (ptr,n) ;
 	xuatmang (ptr,n) ;

 	 printf ("\nInsertion tang dan :") ;
 	insertionIncrease (ptr,n) ;
 	xuatmang (ptr,n) ;

 	printf ("\nInsertion giam dan :") ;
 	insertionDecrease (ptr,n) ;
 	xuatmang (ptr,n) ;

 	free (ptr) ;
 	return 0 ;
}
