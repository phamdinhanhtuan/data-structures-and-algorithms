#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with given data
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    // If head node contains the data
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    // If data not found
    if (temp == NULL) {
        printf("Data not found in the list\n");
        return;
    }
    
    // Unlink the node
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    
    // Insert some nodes
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 0);
    
    // Print the list
    printf("Linked List: ");
    printList(head);
    
    // Delete a node
    deleteNode(&head, 2);
    printf("After deleting 2: ");
    printList(head);
    
    // Free the memory
    freeList(&head);
    
    return 0;
}
