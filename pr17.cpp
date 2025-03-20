#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listHotelRooms {
	int roomId ; 
	char *roomName , *status ; 
} list ; 

typedef struct eachRoomInformation {
	list data ; 
	struct eachRoomInformation *next ; 
} node ;

void inputEachRoom (list *l) {
	int tmp ; 
	do {
		printf ("Please enter the room id : ") ;
		tmp = scanf ("%d",&l->roomId) ;
		while (getchar () != '\n') ;

		if (tmp != 1) {
			printf ("Please enter a valid number !") ;
		} else if (tmp <= 0) {
			printf ("Please enter the positive number !") ;
		}
	} while (tmp != 1 || tmp <= 0) ;

	printf ("Please enter the room name : ") ;
	l->roomName = (char*)malloc (30 * sizeof (char)) ;
	if (l->roomName == NULL) {
		exit (EXIT_FAILURE) ;
	}
	fgets (l->roomName , 30 , stdin) ;
	l->roomName[strcspn (l->roomName,"\n")] = '\0' ;

	printf ("Please enter the status (available or reserved) : ") ;
	l->status = (char*)malloc (30 * sizeof (char)) ;
	if (l->status == NULL) {
		exit (EXIT_FAILURE) ;
	}
	fgets (l->status , 30 , stdin) ;
	l->status[strcspn (l->status,"\n")] = '\0' ;
}

void printEachRoom (list l) {
	printf ("\nThe entered room id : %d" , l.roomId) ;
	printf ("\nThe entered room name : %s" , l.roomName) ;
	printf ("\nThe entered status : %s" , l.status) ;
}

void enterAmount (int *n) {
	int tmp ;
	do {
		printf ("Enter the amount : ") ;
		tmp = scanf ("%d",n) ;

		if (tmp != 1) {
			printf ("Please enter a valid number !") ;
		} else if (*n <= 0) {
			printf ("Please enter the positive number !") ;
		}
	} while (tmp != 1 || *n <= 0) ;
}

node *makeNode (list x) {
	node *newNode = (node*)malloc (sizeof (node)) ;
	if (newNode == NULL) {
		exit (EXIT_FAILURE) ;
	}

	newNode->data.roomId = x.roomId ;

	newNode->data.roomName = (char*)malloc (30 * sizeof (char)) ;
	if (newNode->data.roomName == NULL) {
		exit (EXIT_FAILURE) ;
	}
	strcpy (newNode->data.roomName , x.roomName) ;

	newNode->data.status = (char*)malloc (30 * sizeof (char)) ;
	if (newNode->data.status == NULL) {
		exit (EXIT_FAILURE) ;
	}
	strcpy (newNode->data.status , x.status) ;

	newNode -> next = NULL ; 

	return newNode ;
}

void pushAfter (node **head , list x) {
	node *newNode = makeNode (x) ;
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
	list value ; 
	for (int i = 0 ; i < n ; i++) {
		printf ("Enter the value at position %d : " , i + 1) ;
		inputEachRoom (&value) ;
		pushAfter (head,value) ;
	}
}

void printLinkedList (node *head) {
	if (head == NULL) {
		printf ("\nThe linked list is empty !") ;
		return; 
	}

	while (head != NULL) {
		printEachRoom (head -> data) ;
		head = head -> next ; 
	}
}

void firstRoomAvailable (node *head) {
    int f = 0 ; 
    node *tmp = head;
    while (tmp != NULL) {
        if (strcmp(tmp->data.status,"available") == 0) {
            f = 1;
            printEachRoom(tmp->data);
            break;  
        }
        tmp = tmp->next;
    }
    if (!f) {
        printf("No first room available!\n");
    }
}

int countReservedRooms (node *head) {
	int cnt = 0 ; 
	while (head != NULL) {
		if (strcmp(head->data.status,"reserved")==0) {
			cnt++ ;
		}
		head = head -> next ;
	}
	 return cnt ; 
}

void appendTail (node **head) {
    list x;
    printf("\nEnter the new room details:\n");
    inputEachRoom(&x);

    node *newNode = makeNode(x);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void swap (int *a , int *b) {
	int tmp = *a ; 
	*a = *b ; 
	*b = tmp ;
}

void roomIdIncrease (node **head , int n) {
	if (*head == NULL) {
		printf ("The linked list is empty !") ;
		return  ;
	}

	for (node *i = *head ; i != NULL ; i = i -> next) {
		node *min = i ; 
		for (node *j = i -> next ; j != NULL ; j = j -> next) {
			if (min->data.roomId > j->data.roomId) {
				min = j ; 
			}
		}
		swap (&(i->data.roomId),&(min->data.roomId)) ;
	}
}

void freeLinkedList (node **head) {
	node *tmp = *head ; 
	while (tmp != NULL) {
		node *next = tmp -> next ; 
		free (tmp->data.roomName) ;
		free (tmp->data.status) ;
		free (tmp) ;
		tmp = next ;
	}
	*head = NULL ;
}

int main () {
	int n ; 
	node *head = NULL ;

	enterAmount (&n) ;

	inputLinkedList (&head,n) ;

	printf ("========The entered each room information list======== : ") ;
	printLinkedList (head) ;

	printf ("\n========The first room available is : ======== : ") ;
	firstRoomAvailable (head) ;

	printf("\n========Number of reserved rooms========: %d", countReservedRooms(head));

	printf ("\n========The room added tail is : ======== : ") ;
	appendTail (&head) ;
	printLinkedList (head) ;

	printf ("\n========The room sorted increasing : ======== : ") ;
	roomIdIncrease (&head,n) ;
	printLinkedList (head) ;

	freeLinkedList (&head) ;

	return EXIT_SUCCESS ;
}
