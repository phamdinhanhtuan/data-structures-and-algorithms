#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct qlsv {
	int msv ; 
	char *ht ;
	float dtb ; 
} ql ;

typedef struct Node_SV {
	ql data ; 
	struct Node_SV *next ; 
} node ; 

void nhap1sinhvien (ql *q) {
	printf ("Nhap vao ma sinh vien : ") ;
	scanf ("%d",&q->msv) ;
	while (getchar () != '\n') ;

	printf ("Nhap vao ho va ten sinh vien : ") ;
	fgets(q->ht,50,stdin);
	q->ht[strcspn(q->ht, "\n")] = '\0';
	char *new_qht = (char*)realloc (q->ht,(strlen (q->ht) + 1) * sizeof (char)) ;
	if (new_qht != NULL) {
		q->ht = new_qht ;
	} else {
		printf ("Loi cap phat bo nho ") ; 
		exit (EXIT_FAILURE) ;
	}

	printf ("Nhap vao diem trung binh sinh vien : ") ;
	scanf ("%f",&q->dtb) ;
	while (getchar () != '\n') ;
}

void xuat1sinhvien (ql q) {
	printf ("\nMa sinh vien da nhap la : ") ;
	printf ("%d",q.msv) ;
	printf ("\nHo va ten sinh vien da nhap la : ") ;
	printf ("%s",q.ht);
	printf ("\nDiem trung binh sinh vien da nhap la : ") ;
	printf ("%.2f",q.dtb) ;
}

void nsl (int *n) {
	do {
		printf ("Nhap n ( n > 0 ) : ") ;
		scanf ("%d",n) ;
	} while (*n <= 0) ;
}

node *makeNode (ql x) {
	node *newNode = (node*)malloc (sizeof (node)) ;
	if (newNode == NULL) {
		exit (EXIT_FAILURE) ;
	}
	newNode -> data = x ; 
	newNode -> next = NULL ; 

	return newNode ;
}

void pushAfter (node **head , ql x) {
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
	for (int i = 0 ; i < n ; i++) {
		printf ("Nhap sinh vien thu %d : " , i + 1) ;
		ql tmp ; 
		tmp.ht = (char*)malloc (50 * sizeof (char)) ;
		nhap1sinhvien (&tmp) ;
		pushAfter (head ,tmp) ;
	}
}

void xuatmang (node *head) {
	while (head != NULL) {
		xuat1sinhvien (head->data) ;
		head = head -> next ; 
	}
}

void xuatsinhviendiemtrungbinhlonhon5 (node *head) {
	printf ("Sinh vien co diem trung binh lon hon 5 la : ") ;
	node *tmp = head ; 
	while (tmp != NULL) {
		if (tmp->data.dtb > 5) {
			printf ("%s ", tmp->data.ht) ;
		}
		tmp = tmp -> next ;
	}
}

void giaiphong (node *head) {
	node *tmp = head ;
	while (tmp != NULL) {
		node *next = tmp -> next ; 
		free (tmp->data.ht) ;
		free (tmp) ;
		tmp = next ;
	}
}

int main () {
	int n ; 
	node *head = NULL ;

	nsl (&n) ;

	nhapmang (&head,n) ;

	xuatmang (head) ;

	xuatsinhviendiemtrungbinhlonhon5 (head) ;

	giaiphong (head) ;

	return EXIT_SUCCESS ;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct qlsv {
	int msv ; 
	char *ht ;
	float dtb ; 
} ql ;

typedef struct Node_SV {
	ql data ; 
	struct Node_SV *next ; 
} node ; 

void nhap1sinhvien (ql *q) {
	printf ("Nhap vao ma sinh vien : ") ;
	scanf ("%d",&q->msv) ;
	while (getchar () != '\n') ;

	printf ("Nhap vao ho va ten sinh vien : ") ;
	fgets(q->ht,50,stdin);
	q->ht[strcspn(q->ht, "\n")] = '\0';
	char *new_qht = (char*)realloc (q->ht,(strlen (q->ht) + 1) * sizeof (char)) ;
	if (new_qht != NULL) {
		q->ht = new_qht ;
	} else {
		printf ("Loi cap phat bo nho ") ; 
		exit (EXIT_FAILURE) ;
	}

	printf ("Nhap vao diem trung binh sinh vien : ") ;
	scanf ("%f",&q->dtb) ;
	while (getchar () != '\n') ;
}

void xuat1sinhvien (ql q) {
	printf ("\nMa sinh vien da nhap la : ") ;
	printf ("%d",q.msv) ;
	printf ("\nHo va ten sinh vien da nhap la : ") ;
	printf ("%s",q.ht);
	printf ("\nDiem trung binh sinh vien da nhap la : ") ;
	printf ("%.2f",q.dtb) ;
}

void nsl (int *n) {
	do {
		printf ("Nhap n ( n > 0 ) : ") ;
		scanf ("%d",n) ;
	} while (*n <= 0) ;
}

node *makeNode (ql x) {
	node *newNode = (node*)malloc (sizeof (node)) ;
	if (newNode == NULL) {
		exit (EXIT_FAILURE) ;
	}
	newNode -> data = x ; 
	newNode -> next = NULL ; 

	return newNode ;
}

void pushAfter (node **head , ql x) {
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
	for (int i = 0 ; i < n ; i++) {
		printf ("Nhap sinh vien thu %d : " , i + 1) ;
		ql tmp ; 
		tmp.ht = (char*)malloc (50 * sizeof (char)) ;
		nhap1sinhvien (&tmp) ;
		pushAfter (head ,tmp) ;
	}
}

void xuatmang (node *head) {
	while (head != NULL) {
		xuat1sinhvien (head->data) ;
		head = head -> next ; 
	}
}

void xuatsinhviendiemtrungbinhlonhon5 (node *head) {
	printf ("Sinh vien co diem trung binh lon hon 5 la : ") ;
	node *tmp = head ; 
	while (tmp != NULL) {
		if (tmp->data.dtb > 5) {
			printf ("%s ", tmp->data.ht) ;
		}
		tmp = tmp -> next ;
	}
}

void giaiphong (node *head) {
	node *tmp = head ;
	while (tmp != NULL) {
		node *next = tmp -> next ; 
		free (tmp->data.ht) ;
		free (tmp) ;
		tmp = next ;
	}
}

int main () {
	int n ; 
	node *head = NULL ;

	nsl (&n) ;

	nhapmang (&head,n) ;

	xuatmang (head) ;

	xuatsinhviendiemtrungbinhlonhon5 (head) ;

	giaiphong (head) ;

	return EXIT_SUCCESS ;
}
