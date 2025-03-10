#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node *pre, *next;
} Node;

void init(Node **head) {
    *head = NULL;
}

Node* createNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = x;
    newNode->pre = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node **head, int x) {
    Node *newNode = createNode(x);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->pre = newNode;
    }
    *head = newNode;
}

void insertLast(Node **head, int x) {
    Node *newNode = createNode(x);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    newNode->pre = p;
}

void inputList(Node **head) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertLast(head, x);
    }
}

void outputList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d <-> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void outputReverse(Node *head) {
    if (head == NULL) return;
    Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    while (p != NULL) {
        printf("%d <-> ", p->info);
        p = p->pre;
    }
    printf("NULL\n");
}

void deleteFirst(Node **head) {
    if (*head == NULL) return;
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->pre = NULL;
    }
    free(temp);
}

void deleteLast(Node **head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->pre->next = NULL;
    free(p);
}

void deleteElement(Node **head, int z) {
    if (*head == NULL) return;
    if ((*head)->info == z) {
        deleteFirst(head);
        return;
    }
    Node *p = *head;
    while (p != NULL && p->info != z) {
        p = p->next;
    }
    if (p == NULL) return;
    if (p->next != NULL) {
        p->next->pre = p->pre;
    }
    if (p->pre != NULL) {
        p->pre->next = p->next;
    }
    free(p);
}

int count(Node *head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

int max(Node *head) {
    if (head == NULL) return -1;
    int maxVal = head->info;
    while (head != NULL) {
        if (head->info > maxVal) maxVal = head->info;
        head = head->next;
    }
    return maxVal;
}

int min(Node *head) {
    if (head == NULL) return -1;
    int minVal = head->info;
    while (head != NULL) {
        if (head->info < minVal) minVal = head->info;
        head = head->next;
    }
    return minVal;
}

void sort(Node *head) {
    for (Node *i = head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

int main() {
    Node *head;
    init(&head);
    inputList(&head);
    outputList(head);
    outputReverse(head);
    sort(head);
    outputList(head);
    printf("%d\n", max(head));
    printf("%d\n", min(head));
    printf("%d\n", count(head));
    deleteElement(&head, head->info);
    outputList(head);
    deleteLast(&head);
    outputList(head);
    return 0;
}
