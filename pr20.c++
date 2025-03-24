#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct manageStudents {
	int studentsId ; 
	char *fullName ; 
	float average ; 
} manage ; 

typedef struct nodeManageStudents {
	manage data; 
	struct nodeManageStudents *next ;
} node ;

void lexit () {
	exit (EXIT_FAILURE) ;
}

void clearBuffer () {
	while (getchar () != '\n') ;
}

void enterAmount (int *n) {
	int tmp ; 
	do {
		printf("Enter the amount (n > 0) : ");
		tmp = scanf ("%d",n) ;
		clearBuffer () ;

		if (tmp != 1 || *n <= 0) {
			printf ("Please enter a valid number !\n") ;
		}
	} while (tmp != 1 || *n <= 0) ;
}

node* makeNode (manage value) {
	node *newNode = (node*)malloc (sizeof (node)) ;
	if (newNode == NULL) lexit () ;

	newNode->data.studentsId = value.studentsId ;
	newNode->data.average = value.average ; 
	newNode->data.fullName = (char*)malloc (30 * sizeof (char)) ;
	if (newNode->data.fullName == NULL) lexit () ;
	strcpy (newNode->data.fullName , value.fullName) ;

	newNode -> next = NULL ;

	return newNode ;
}

void pushAfter (node **head , manage value) {
	if (*head == NULL) {
		*head = makeNode (value) ; return ; 
	}

	node *tmp = *head , *newNode = makeNode (value) ;
	while (tmp -> next != NULL) {
		tmp = tmp -> next ;
	}

	tmp -> next = newNode ; 
}

void inputStudent (manage *m) {
	printf ("Enter the student id : ") ;
	scanf ("%d",&m->studentsId) ;
	clearBuffer () ;

	printf ("Enter the full name : ") ;
	m->fullName = (char*)malloc (30 * sizeof (char)) ;
	if (m->fullName == NULL) lexit () ;
	fgets (m->fullName , 30 , stdin) ;
	m->fullName [strcspn (m->fullName , "\n")] = '\0' ;

	printf ("Enter the average : ") ;
	scanf ("%f",&m->average) ;
	clearBuffer () ;
}

void printfStudent (manage m) {
	printf ("\nEntered the student id : %d",m.studentsId) ;
	printf ("\nEntered the full name : %s",m.fullName) ;
	printf ("\nEntered the average id : %.2f",m.average) ;
}

void printfStudentWithAverageAbove5 (node *head) {
	int f = 0 ;

	while (head != NULL) {
		if (head->data.average > 5.0) {
			f = 1 ; 
			printfStudent (head->data) ;
		}
		head = head -> next ;
	}

	if (!f) {
		printf ("No student has average above 5 !") ;
	}
}

void inputLinkedList (node **head , int n) {
	manage value ; 
	for (int i = 0 ; i < n ;i++) {
		printf ("Enter the student at position %d !\n" , i) ;
		inputStudent (&value) ;
		pushAfter (head,value) ;
	}
}

manage appStudentTail (node **head) {
	manage newStudent ;
	printf ("Enter a new student !\n") ; 
	inputStudent (&newStudent) ;
	pushAfter (head,newStudent) ;

	return newStudent ;
}

void printfLinkedList (node *head) {
	while (head != NULL) {
		printfStudent (head -> data) ;
		head = head -> next ;
	}
}

int countStudents (node *head) {
	int cnt = 0 ; 
	while (head != NULL) {
		cnt++ ;
		head = head -> next ;
	}

	return cnt; 
}

void printInformationStudentK (node *head) {
	int pos , tmp ;
	do {
		printf("Enter the pos need print information (n > 0) : ");
		tmp = scanf ("%d",&pos) ;
		clearBuffer () ;

		if (tmp != 1 || pos <= 0) {
			printf ("Please enter a valid position !\n") ;
		}
	} while (tmp != 1 || pos <= 0) ;

	int i = 1 ; 
	while (head != NULL && i < pos) {
		i++ ;
		head = head -> next; 
	}

	printf ("The information at %d : ", pos) ;
	printfStudent (head->data) ;
}

int main () {
	int choice , tmp , n ;
	node *head = NULL ;

	do {
		printf ("\n===============MENU===============") ;
		printf ("\n1.Enter the linked list !") ;
		printf ("\n2.Print the linked list !") ;
		printf ("\n3.Print the students with average above 5 !") ;
		printf ("\n4.Adding a new student tail !") ;
		printf ("\n5.Total student !") ;
		printf ("\n6.Print student at position k !") ;
		printf ("\n0.Break !") ;
		printf ("\n===============MENU===============\n") ;

		do {
			printf ("Please your option : ") ;
			tmp = scanf ("%d",&choice) ;
			if (tmp != 1 || choice < 0) {
				printf ("Please a valid number !") ;
			}
		} while (tmp != 1 || choice < 0) ;

		switch (choice) {
		case 1 : 
			printf ("You picked the option 1!\n") ;
			enterAmount (&n) ;
			inputLinkedList (&head,n) ;
			break ;
		case 2 : 
			if (head == NULL) {
				printf ("You need to pick 1 first !") ;
			} else {
				printf ("The linked list entered : ") ;
				printfLinkedList (head) ;
			}
			break ; 
		case 3 : 
			if (head == NULL) {
				printf ("You need to pick 1 first !") ;
			} else {
				printfStudentWithAverageAbove5 (head) ;
			}
			break ;
		case 4 : 
			if (head == NULL) {
				printf ("You need to pick 1 first !") ;
			} else {
				appStudentTail (&head) ;
				printf ("The linked list updated (add a new student)...\n") ;
				printfLinkedList (head) ;
			}
			break ;
		case 5 : 
			if (head == NULL) {
				printf ("You need to pick 1 first !") ;
			} else {
				printf ("Total number students : %d",countStudents (head)) ;
			}
			break ;
		case 6 : 
			if (head == NULL) {
				printf ("You need to pick 1 first !") ;
			} else {
				printf ("The information of student at position k ! ") ;
				printInformationStudentK (head) ;
			}
		}
	} while (choice != 0) ;

	return EXIT_SUCCESS ;
}
