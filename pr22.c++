#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct integerSequence {
	int data ; 
	struct integerSequence *next ;
} node ;

void clearBuffer () {
	while (getchar () != '\n') ;
}

void lexit () {
	exit (EXIT_FAILURE) ;
}

node *makeNode (int value) {
	node *newNode = (node*)malloc(sizeof (node)) ;
	if (newNode == NULL) lexit () ;

	newNode -> data = value ;
	newNode -> next = NULL ;

	return newNode ;
}

void appendTail (node **head , int value) {
	if (*head == NULL) {
		*head = makeNode (value) ; return ;
	}

	node *newNode = makeNode (value) , *tmp = *head ;
	while (tmp -> next != NULL) {
		tmp = tmp -> next ;
	}

	tmp -> next = newNode ;
}

void enterMount (int *n) {
	while (1) {
		printf ("Enter the amount : ") ; 
		if ((scanf ("%d",n)) == 1 && *n > 0) {
			break ;
		}
		printf ("Please enter a valid number !\n") ;
		clearBuffer () ;
	}
}

void inputLinkedList (node **head , int n) {
	int value ; 
	for (int i = 0 ; i < n ;i++) {
		printf ("Enter the valid of the element at position %d : " , i) ;
		scanf ("%d",&value) ;
		appendTail (head,value) ;
	}
}

void printLinkedList (node *head) {
	while (head != NULL) {
		printf ("%d " , head -> data) ;
		head = head -> next ;
	}
}

void swap (int *a , int *b) {
	int tmp = *a ; 
	*a = *b ;
	*b = tmp ;
}

void arrangeLinkedListIncreasing (node **head) {
	for (node *i = *head ; i != NULL ; i = i -> next) {
		node *min = i ;
		for (node *j = i -> next ; j != NULL ; j = j -> next) {
			if (j->data > min->data) {
				min = j ; 
			}
		}
		swap (&i->data , &min->data) ;
	}
}

void pushAfterZ (node **head) {
	if (*head == NULL) return ; 

	int z , f = 0 , value ;
	scanf ("%d",&value) ;

	while (1) {
		printf ("Enter the element z need to add after : ") ;
		if (((scanf ("%d",&z)) == 1) && z > 0) {
			break ;
		}
		printf ("Please enter a valid position !\n") ;
		clearBuffer () ;
	}

	node *tmp = *head , *newNode = makeNode (value) ;
	while (tmp != NULL) {
		if (tmp->data == z) {
			f = 1 ;
			newNode -> next = tmp -> next ;
			tmp -> next = newNode ;
			break ; 
		}
		tmp = tmp -> next ;
	}

	if (!f) {
		printf ("Don't have the element z need to find !\n") ;
		free (newNode) ;
	}
}

void popFront (node **head) {
	if (*head == NULL) return ; 
	node *tmp = *head ; 
	*head  = tmp -> next ; 
	free (tmp) ;
	return ;
}

void popZ (node **head) {
	int z ; 
	while (1) {
		if ((scanf ("%d",&z)) == 1 && z > 0) {
			break ;
		}
		printf ("Please enter a valid number !") ;
		clearBuffer () ;
	}

	node *tmp = *head ;
	while (tmp != NULL) {
		if (tmp->data == z) {
			popFront (head) ;
			return ;
		} else if (tmp -> next != NULL && tmp -> next -> data == z) {
			node *deleted = tmp -> next ; 
			tmp -> next = tmp -> next -> next ;
			free (deleted) ;
			return ;
		} else {
			tmp = tmp -> next ;
		}
	}
}

void popAllLinkedList (node **head) { 
	if (*head == NULL) return ;
	while (*head != NULL) {
		popFront (head) ;
	}
	*head = NULL ;
}

int countNodeLinkedList (node *head) {
	int cnt = 0;
	if (head == NULL) return -1;
	while (head != NULL) {
		cnt++ ;
		head = head -> next ;
	}

	return cnt ;
}

void valueAtpositionK (node *head) {
	int k;
	while (1) {
		printf ("Enter the position k need to extract data : ") ;
		if ((scanf ("%d",&k)) == 1 && k > 0) {
			break ;
		}
		printf ("Please enter a valid position k !") ;
		clearBuffer () ;
	}

	if (head == NULL) return ;	

	int index = 1 ;
	while (head != NULL && index < k) { 
		index++ ;
		head = head -> next ;
	}

	if (head -> next == NULL) {
		printf ("Out of range !\n") ; return ;
	}

	printf ("The value at index %d : " , k) ;
	printf ("%d",head->data) ;
}

void findTheElementMax (node *head) {
	if (head == NULL) return ;

	int max = head->data ;
	node *tmp = head ;
	while (tmp != NULL) {
		if (tmp->data > max) {
			max = tmp -> data ;
		}
		tmp = tmp -> next ;
	}

	printf ("The valux max in linked list : %d",tmp -> data) ;
}

void freeLinkedList (node **head) {
	node *tmp = *head ;
	while (tmp != NULL) {
		node *next = tmp -> next ;
		free (tmp) ;
		tmp = next ;
	}
	*head = NULL ;
}

int main () {
	int n , choice ; 
	node *head = NULL ; 

	do {
		printf ("====================MENU====================") ;
		printf ("\n1.Input linked list !") ;
		printf ("\n2.Print linked list !") ;
		printf ("\n3.Arraging the linked list increasing !") ;
		printf ("\n4.Finding the element z , then , add after it !") ;
		printf ("\n5.Pop the element front !") ;
		printf ("\n6.Pop the element with value z !") ;
		printf ("\n7.Pop all the element !") ;
		printf ("\n8.Count all node in linked list !") ;
		printf ("\n9.Print data at position k with k begin from 0 !") ;
		printf ("\n0.Exit !") ;
		printf ("\n====================MENU====================\n") ;

		while (1) {
			printf ("Enter your option : ") ;
			if ((scanf ("%d",&choice)) == 1 && choice >= 0) {
				break ;
			}
			printf ("Please enter a valid option !\n") ;
			clearBuffer () ;
		}

		switch (choice) {
		case 1 :
			printf ("You picked 1\n") ;
			enterMount (&n) ;
			freeLinkedList (&head) ;
			inputLinkedList (&head,n) ;
			break ;
		case 2 :
			printf ("You picked 2\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				printf ("The linked list entered : ") ;
				printLinkedList (head) ;
			}
			break ;
		case 3 :
			printf ("You picked 3\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				printf ("The linked list before arranging : ") ;
				printLinkedList (head) ;
				printf ("The linked list after arranging : ") ;
				arrangeLinkedListIncreasing (&head) ;
				printLinkedList (head) ;
			}
			break ;
		case 4 :
			printf ("You picked 4\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				printf ("Adding after the element z : ") ;
				pushAfterZ (&head) ;
				printf ("The linked list after adding z : ") ;
				printLinkedList (head) ;
			}
			break ;
		case 5 :
			printf ("You picked 5\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				popFront (&head) ;
				printf ("The linked list after pop front : ") ;
				printLinkedList (head) ;
			}
			break ;
		case 6 :
			printf ("You picked 6\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				popZ (&head) ;
				printf ("The linked list after pop z : ") ;
				printLinkedList (head) ;
			}
			break ;
		case 7 :
			printf ("You picked 7\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				popAllLinkedList (&head) ;
				printf ("The linked list after pop all : ") ;
				printLinkedList (head) ;
			}
			break ;
		case 8 :
			printf ("You picked 8\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				printf ("Total node in linked list : %d",countNodeLinkedList (head)) ;
			}
			break ;
		case 9 :
			printf ("You picked 9\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				printf ("The value of the element at index k : ") ;
				valueAtpositionK (head) ;
			}
			break ;
		case 10 : 
			printf ("You picked 10\n") ;
			if (head == NULL) {
				printf ("The linked list is emptying !\nYou need to pick 1 at first !\n") ;
			} else {
				printf ("The element max in linked list : ") ;
				findTheElementMax (head) ;
			}
		case 0 :
			printf ("You picked 0\n") ;
			break ;
		default : 
			printf ("You need to pick a valid number from 0 to 9 !\n") ;
		}
	} while (choice != 0) ;

	return EXIT_SUCCESS ;
}
