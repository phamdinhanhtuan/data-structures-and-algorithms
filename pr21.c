#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct patient {
	int patientNumber , age ;
	char *fullName ; 
} patient ; 

typedef struct queue {
	int front , rear , size ;  
	patient *data ; 
} circular ; 

void memoryAllocation (circular *q , int size) { 
	q->data = (patient*) malloc (size * sizeof (patient)) ;
	if (q->data == NULL) exit (EXIT_FAILURE) ;

	for (int i = 0 ; i < size ; i++) {
		q->data[i].fullName = (char*)malloc (30 * sizeof (char)) ;
		if (q->data[i].fullName == NULL) exit (EXIT_FAILURE) ;
	}
	q->size = size ;
}

void freeAllocation (circular *q) {
	for (int i = 0 ; i < q->size ;i++) {
		free(q->data[i].fullName) ;
	}
	free (q->data) ;
}

void init (circular *q) {
	q->front = -1 ; 
	q->rear = -1 ;
}

int isEmpty (circular *q) {
	return q->front == -1 ;
}

int isFull (circular *q) {
	return (q->rear + 1) % q->size == q->front ;
}

bool isSamePatientNumber (circular *q , int patientNumber) {
	if (isEmpty (q)) return false ;
	int i = q->front ; 
	while (1) {
		if (q->data[i].patientNumber == patientNumber) return true ; 
		if (q->rear == i) break ;
		i = (i + 1) % q->size ;
	}

	return false ;
}

void addPatient (circular *q , patient *p) {
	if (isFull (q)) {
		printf ("The queue is full ! Cannot add patient !\n") ; return ; 
	}

	if (isEmpty (q)) q->front = 0 ;

	if (isSamePatientNumber(q,p->patientNumber)) {
		printf ("The patient already servival !") ;
		return ;
	}

	q->rear = (q->rear + 1) % q->size ; 
   q->data[q->rear].patientNumber = p->patientNumber;
    q->data[q->rear].age = p->age;
    strcpy(q->data[q->rear].fullName, p->fullName);

    free(p->fullName);
}

patient getThepatientNext (circular *q) {
	patient empty ;
	empty.fullName = NULL ;
	empty.age = 0 ;
	empty.patientNumber = 0 ;
	if (isEmpty (q)) return empty ; 
	
	patient p = q->data[q->front] ;

	if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }

    return p ; 
}

int remaningPatient (circular *q) {
	if (isEmpty(q)) return -1 ; 

	if (q->rear >= q->front) {
		return q->rear - q->front + 1 ;
	} else {
		return q->size - q->front + q->rear + 1 ;
	}
}

void clearBuffet () {
	while (getchar () != '\n') ;
}

void inputPatient (patient *p) {
	int tmp ;
	do {
		printf ("Enter the patient number : ") ;
		tmp = scanf ("%d",&p->patientNumber) ;
		clearBuffet () ;

		if (tmp != 1) {
			printf ("Please enter a valid number!") ;
		} else if (p->patientNumber <= 0) {
			printf ("Please enter a positive number !") ;
		}
	} while (tmp != 1 || p->patientNumber <= 0) ;

	do {
		printf ("Enter the age : ") ;
		tmp = scanf ("%d",&p->age) ;
		clearBuffet () ;
		
		if (tmp != 1) {
			printf ("Please enter a valid number!") ;
		} else if (p->age <= 0) {
			printf ("Please enter a positive number !") ;
		}
	} while (tmp != 1 || p->age <= 0) ;

	if (p->fullName == NULL) {
		printf ("Err") ;
		exit (EXIT_FAILURE) ;
	}
	printf ("Enter the full name : ") ;
	fgets (p->fullName , 30 , stdin) ;
	p->fullName[strcspn (p->fullName,"\n")] = '\0' ;
}

void printPatient (patient *p) {
	printf ("\nThe enterd patient number : %d" , p->patientNumber) ;
	printf ("\nThe enterd age : %d" , p->age) ;
	printf ("\nThe enterd full name : %s" , p->fullName) ;
}

void listPatentWaiting (circular *q) {
	if (isEmpty (q)) return ; 
	int i = q->front ; 
	while (1) {
		printPatient (&(q->data[i])) ;
		if (q->rear == i) break ;
		i = (i + 1) % q->size ;
	}
}

int main () {
	circular q ;
	int choice , tmp ; 
	char c ;

	printf ("=================================================") ;
    printf ("\n1.Adding a new patient !  ") ;
    printf ("\n2.Getting the patient's information !  ") ;
    printf ("\n3.Count the number of patient examined !  ") ;
    printf ("\n4.Count the number of patient unexamined !  ") ;
    printf ("\n5.The list patients is waiting !  ") ;
    printf ("\n0.break !") ;
	printf ("\n=================================================\n") ;
	
	memoryAllocation (&q,30) ;

	init (&q) ;
	
	do {
		do {
			printf ("Please enter your option : ") ;
			tmp = scanf ("%d",&choice) ;
			clearBuffet () ;
			
			if (tmp != 1 || choice < 0) {
				printf ("Please enter a valid number !") ;
			}
		} while (tmp != 1 || choice < 0) ;

		switch (choice) {
		case 1 :
			do {
    patient newPatient;
    printf("Adding a new patient .... !\n");
    inputPatient(&newPatient);
    addPatient(&q, &newPatient);

    printf("\nWould you like to continue adding patients (y or n)? ");
    scanf(" %c", &c);
    
    while (getchar() != '\n');  // Xóa bộ đệm nhập để tránh lỗi

    while (c != 'y' && c != 'n') {
        printf("If you want to input the patient, please just enter y or n!\n");
        while (getchar() != '\n');  // Xóa bộ đệm trước khi nhận ký tự mới
        scanf(" %c", &c);
    }
} while (c == 'y');

			break ;
		// case 2 : 
		}
	} while (choice != 0) ;
	
	freeAllocation (&q) ;

	return EXIT_SUCCESS ;
}


