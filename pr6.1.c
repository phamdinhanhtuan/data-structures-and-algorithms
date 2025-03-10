#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void init(Node** head) {
    *head = NULL;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void inputList(Node** head) {
    int n, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertFirst(head, value);
    }
}

void outputList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void sortList(Node* head) {
    Node* i;
    Node* j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void deleteFirst(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteElement(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return;
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

void deleteAll(Node** head) {
    Node* current = *head;
    Node* temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;
}

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int valueAt(Node* head, int index) {
    Node* current = head;
    int pos = 0;
    while (current != NULL && pos < index) {
        current = current->next;
        pos++;
    }
    if (current == NULL) return -1;
    return current->data;
}

int findMax(Node* head) {
    int max = head->data;
    Node* current = head->next;
    while (current != NULL) {
        if (current->data > max) max = current->data;
        current = current->next;
    }
    return max;
}

int findMin(Node* head) {
    int min = head->data;
    Node* current = head->next;
    while (current != NULL) {
        if (current->data < min) min = current->data;
        current = current->next;
    }
    return min;
}

int main() {
    Node* head;
    init(&head);
    inputList(&head);
    outputList(head);
    sortList(head);
    outputList(head);
    int value;
    scanf("%d", &value);
    deleteElement(&head, value);
    outputList(head);
    deleteFirst(&head);
    outputList(head);
    printf("%d\n", countNodes(head));
    int index;
    scanf("%d", &index);
    printf("%d\n", valueAt(head, index));
    printf("%d\n", findMax(head));
    printf("%d\n", findMin(head));
    deleteAll(&head);
    outputList(head);
    return 0;
}
``` 
