#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data ; 
	struct node *next ; 
} node ; 

void nsl (int *n) {
	do {
		printf ("Nhap n ( n > 0 ) : ") ;
		scanf ("%d",n) ;
	} while (*n <= 0) ;
}

node *makeNode (int x) {
	node *newNode = (node*)malloc (sizeof(node)) ;
	if (newNode == NULL) {
		exit (EXIT_FAILURE) ;
	}

	newNode -> data = x ; 
	newNode -> next = NULL ; 

	return newNode ; 
}

void pushAfter (node **head , int x) {
	node *newNode = makeNode (x) ;

	if (*head == NULL) {
		*head = newNode ; return ;
	}

	node *tmp = *head ;
	while (tmp -> next != NULL) {
		tmp = tmp -> next ;
	}

	tmp -> next = newNode ;
}

void nhapmang (node **head , int n) {
	int x ;
	for (int i = 0 ; i < n ;i++) {
		printf ("Nhap vao phan tu thu %d : " , i + 1) ;
		scanf ("%d",&x) ;
		pushAfter (head,x) ;
	}
}

void xuatmang (node *head) {
	while (head != NULL) {
		printf ("%d " , head->data) ;
		head = head -> next ;
	}
}

void swap (int *a , int *b) {
	int tmp = *a ; 
	*a = *b ; 
	*b = tmp ;
}

void arrange (node **head) {
	for (node *i = *head ; i != NULL ; i = i -> next) {
		node *minNode = i ; 
		for (node *j = i -> next ; j != NULL ; j = j -> next) {
			if (minNode->data > j->data) {
				minNode = j ; 
			}
		}
		swap (&minNode->data , &i->data) ;
	}
}

void addAfterIfFind (node **head) {
	int zz , f = 0 ;
	printf ("\nNhap vao so z can them gia tri phia sau : ") ;
	scanf ("%d",&zz) ;

	if (*head == NULL) return ;

	node *tmp = *head ;
	while (tmp -> next!= NULL) {
		if (tmp->next->data == zz) {
			f = 1 ; 
			node *newNode = makeNode (zz) ; 
			newNode -> next = tmp -> next ; 
			tmp -> next = newNode ; 
			tmp = newNode -> next ; 
		} else {
			tmp = tmp -> next ; 
		}
	}

	if (f == 0) {
		printf ("Khong ton tai gia tri z ") ;
	} else {
		printf ("Da them node vao sau gia tri z ") ;
	}
} 

void popFront (node **head) {
	if (*head == NULL) return ; 

	node *tmp = *head ; 
	*head = (*head)->next ;

	free (tmp) ;
}

void popZ (node **head) {
	node *tmp = *head ; 
	int z , f = 0 ;
	printf ("\nNhap vao gia tri z can xoa : ") ;
	scanf ("%d",&z) ;

	if (*head == NULL) return ; // rỗng

	if (tmp != NULL && tmp->data == z) { // có 1 node
		popFront (head) ;return ;
	} 

	while (tmp -> next != NULL) { // xóa các node tiếp theo
		if (tmp -> next -> data == z) {
			node *Delete = tmp -> next ; 
			tmp -> next = tmp -> next -> next ;
			free (Delete) ;
			f = 1 ;
		} else {
			tmp = tmp -> next ;
		}		
	}	

	if (f == 0) {
		printf ("Khong ton tai gia tri z") ;
	} else {
		printf ("Da xoa node vao sau gia tri z ") ;
	}
}

int main () {
	int n ; 
	node *head = NULL ;

	nsl (&n) ;

	nhapmang (&head,n) ;;

	printf ("Mang da nhap la : ") ;
	xuatmang (head) ;

	printf ("\nDSLK sau khi sap xep la : ") ;
	arrange (&head) ;
	xuatmang (head) ;

	addAfterIfFind (&head) ;
	printf ("\nMang sau khi them : ") ;
	xuatmang (head) ;

	popFront (&head) ;
	printf ("\nDSLK sau khi xoa mot phan tu dau tien : ") ;
	xuatmang (head) ;

	popZ (&head) ;
	printf ("\nDSLK sau khi xoa z la : ") ;
	xuatmang (head) ;

	return EXIT_SUCCESS ; 
}
