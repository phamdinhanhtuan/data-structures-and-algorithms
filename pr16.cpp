#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct inventoryList {
	int itemCode , stockQuantity ; 
	char *itemFullName ;
} in ; 

typedef struct nodeInvertoryList {
	in data ; 
	struct nodeInvertoryList *next ; 
} node ; 

void inputItem (in *i) {
	int tmp , tmp1 ;
	do {
		printf ("Enter the item code : ") ;
		tmp = scanf ("%d",&i->itemCode) ;
		while (getchar () != '\n') ;

		if (tmp != 1) {
			printf ("Please enter a valid number !") ;
		} else if (i->itemCode <= 0) {
			printf ("Please enter a positive number !") ;
		}
	} while (tmp != 1 || (i->itemCode) <= 0) ;

	do {
		printf ("Enter the stock quanlity : ") ;
		tmp1 = scanf ("%d",&i->stockQuantity) ;
		while (getchar () != '\n') ;

		if (tmp1 != 1) {
			printf ("Please enter a valid number !") ;
		} else if (i->stockQuantity <= 0) {
			printf ("Please enter a positive number !") ;
		}
	} while (tmp1 != 1 || (i->stockQuantity) <= 0) ;

	i->itemFullName = (char*)malloc (30 * sizeof (char)) ;
	if (i->itemFullName == NULL) {
		exit (EXIT_FAILURE) ;
	}
	printf ("Enter the full name of the item : ") ;
	fgets (i->itemFullName,30,stdin) ;
	i->itemFullName[strcspn (i->itemFullName, "\n")] = '\0' ;
}

void printItem (in i) {
	printf ("\nThe entered item code is : %d",i.itemCode) ;
	printf ("\nThe entered stock quanlity is : %d",i.stockQuantity) ;
	printf ("\nThe entered full name of the item is : %s",i.itemFullName) ;
}

void enterAmount (int *n) {
	int tmp ;
	do {
		printf ("Please enter the amount : ") ;
		tmp = scanf ("%d",n) ;
		while (getchar () != '\n') ;

		if (tmp != 1) {
			printf ("Please enter a valid number !") ;
		} else if (*n <= 0) {
			printf ("Please enter a positive number !") ;
		}
	} while (tmp != 1 || *n <= 0) ;
}

node *createNode (in x) {
	node *newNode = (node*)malloc (sizeof (node)) ;
	if (newNode == NULL) {
		exit (EXIT_FAILURE) ;
	}

	newNode -> data.itemCode = x.itemCode ; 
	newNode -> data.stockQuantity = x.stockQuantity; 

	newNode ->data.itemFullName = (char*)malloc (30 * sizeof (char)) ;
	if (newNode ->data.itemFullName == NULL) {
		exit (EXIT_FAILURE) ;
	}
	strcpy (newNode ->data.itemFullName , x.itemFullName) ;

	newNode -> next = NULL ; 

	return newNode ; 
}

void pushAfter (node **head , in x) {
	node *newNode = createNode  (x) ;
	if (*head == NULL) {
		*head = newNode ; 
		return ;
	}

	node *tmp = *head ; 
	while (tmp -> next != NULL) {
		tmp = tmp -> next ;
	}

	tmp -> next = newNode ; 
}

void inputLinkedList (node **head , int n) {
	in value ; 
	for (int i = 0 ; i < n ; i++) {
		printf ("Enter the value at position %d : " , i + 1) ;
		inputItem (&value) ;
		pushAfter (head,value) ;
	}
}

void printLinkedList (node *head) {
	if (head == NULL) {
		printf ("\nThe linked list is empty !") ;
		return; 
	}

	while (head != NULL) {
		printItem (head -> data) ;
		head = head -> next ; 
	}
}

void lookThroughItemWithCodeX (node *head) {
	int value , f = 0 , tmp1 ;  
	do {
		printf ("\nEnter the code need to look through : ") ;
		tmp1 = scanf ("%d",&value) ;
		while (getchar () != '\n') ;

		if (tmp1 != 1) {
			printf ("Please enter a valid number !") ;
		} else if (tmp1 <= 0) {
			printf ("Please enter a positive number !") ;
		}
	} while (tmp1 != 1 || tmp1 <= 0) ;

	node *tmp = head ; 
	while (tmp != NULL) {
		if (tmp->data.itemCode == value) {
			printItem  (tmp -> data) ;
			f = 1 ;
		}
		tmp = tmp -> next ; 
	}

	if (!f) {
		printf ("No item code X look through !") ;
	}
}

void addItemAfterItemcodeX (node **head) {
	int value , f = 0 , tmp1 ;
	in x ; 
	do {
		printf ("\nEnter the item code to add pushAfter : ") ;
		tmp1 = scanf ("%d",&value) ;
		while (getchar () != '\n') ;

		if (tmp1 != 1) {
			printf ("Please enter a valid number !") ;
		} else if (tmp1 <= 0) {
			printf ("Please enter a positive number !") ;
		}
	} while (tmp1 != 1 || tmp1 <= 0) ;

	node *tmp = *head ; 
	while (tmp != NULL) {
		if (tmp -> data.itemCode == value) {
			f = 1 ; 
			inputItem (&x) ;
			node *newNode = createNode (x) ;
			newNode -> next = tmp -> next  ; 
			tmp -> next = newNode ; 
			tmp = newNode -> next ; 
		} else {
			tmp = tmp -> next ; 
		}
	}

	if (!f) {
		printf ("No item code X look through for deleting!") ;
	}	
}

void popFrontInventoryList (node **head) {
	if (*head == NULL) return ; 

	node *tmp = *head ; 
	*head = tmp -> next ; 
	free (tmp->data.itemFullName) ;
	free (tmp) ;
}

void deleteAllLinkedListWithConfirm (node **head) {
	char confirm ; 
	do {
		printf ("\nAre you sure to delete entire the entire linked list ? Y or N ? : ") ;
		scanf (" %c",&confirm) ;
		while (getchar () != '\n') ;
		if (confirm != 'Y' && confirm != 'N') { 
            printf("Invalid input! Please enter Y or N\n");
        }
	} while (confirm != 'Y' && confirm != 'N');

	if (confirm == 'Y') {
        node *tmp = *head, *next;
        while (tmp != NULL) {
            next = tmp->next;
            free(tmp->data.itemFullName);
            free(tmp);
            tmp = next;
        }
        *head = NULL;
        printf("=>>> The entire linked list deleted!\n");
    } else {
        printf("=>>> List deletion canceled!\n");
    }
}

void deleteItemcodeX (node **head) {
	int x , f = 0 ; 
	printf ("\nEnter the item code to delete : ") ;
	scanf ("%d",&x) ;
	while (getchar () != '\n') ;

	if (*head == NULL) { 
		printf ("The linked list is empty ") ;
		return ; 
	}

	node *tmp = *head , *prev = NULL ; 
	while (tmp != NULL) {
		if (tmp->data.itemCode == x) {
			f = 1 ; 
			if (tmp == *head) {
				*head = tmp -> next ; 
				free (tmp->data.itemFullName) ;
				free (tmp) ;
			} else {
				prev -> next = tmp -> next ; 
				free (tmp->data.itemFullName) ;
				free (tmp) ;
			} 
		}	
		else {
				prev = tmp ; 
				tmp = tmp ->next ; 
			}
		}

	if (!f) {
		printf ("No item with code to delete !") ;
	}
}

void freeLinkedList (node **head) {
	node *tmp = *head , *next ;  
	while (tmp != NULL) {
		next = tmp -> next ; 
		free (tmp->data.itemFullName) ;
		free (tmp) ;
		tmp = next ;
	}
	*head = NULL ;
}

void swap (node *a , node *b) {
	in tmp = a -> data ; 
	a -> data = b -> data ; 
	b -> data = tmp ;
}

void LinkedListIncrease (node **head , int n) {
	if (*head == NULL) {
		printf ("The linked list is empty !") ;
		return  ;
	}

	for (node *i = *head ; i != NULL ; i = i -> next) {
		node *min = i ; 
		for (node *j = i -> next ; j != NULL ; j = j -> next) {
			if (strcmp (min->data.itemFullName ,j->data.itemFullName) > 0) {
				min = j ; 
			}
		}
		swap (i,min) ;
	}
}

int main () {
	int n ; 
	node *head = NULL ;

	enterAmount (&n) ;

	inputLinkedList (&head,n) ;

	printf ("========The entered inventory list======== : ") ;
	printLinkedList (head) ;

	printf ("\nThe item code X need to look through is :") ;	
	lookThroughItemWithCodeX (head) ;

	addItemAfterItemcodeX (&head) ;
	printf ("\n========Linked list updated (add after)======== : ") ;
	printLinkedList (head) ;

	popFrontInventoryList (&head) ;
	printf ("\n========Linked list updated (pop front)======== : ") ;
	printLinkedList (head) ;

	deleteAllLinkedListWithConfirm (&head) ;
	printf ("\n========Linked list updated (pop all items)======== : ") ;
	printLinkedList (head) ;

	deleteItemcodeX (&head) ;
	printf ("\n========Linked list updated (deleted item)======== : ") ;
	printLinkedList (head) ;

	LinkedListIncrease (&head,n) ;
	printf ("\n========Linked list updated (sort)======== : ") ;
	printLinkedList (head) ;

	if (head != NULL) {
		freeLinkedList (&head) ;
	}

	return EXIT_SUCCESS ;
}
