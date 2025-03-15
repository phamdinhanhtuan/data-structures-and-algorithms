#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} Node;

typedef Node* STACK;

void init(STACK *s) {
    *s = NULL;
}

int isEmpty(STACK s) {
    return s == NULL;
}

void push(STACK *s, int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = x;
    newNode->next = *s;
    *s = newNode;
}

int pop(STACK *s, int *x) {
    if (isEmpty(*s)) {
        return 0;
    }
    Node *temp = *s;
    *x = temp->info;
    *s = temp->next;
    free(temp);
    return 1;
}

void convert(int n, STACK *s) {
    int soda;
    while (n > 0) {
        soda = n % 2;
        push(s, soda);
        n = n / 2;
    }
}

void output(STACK s) {
    int x;
    while (!isEmpty(s)) {
        pop(&s, &x);
        printf("%d", x);
    }
    printf("\n");
}

int main() {
    STACK s;
    int n;

    init(&s);

    printf("Nhap so he thap phan: ");
    scanf("%d", &n);

    convert(n, &s);

    printf("So nhi phan: ");
    output(s);

    return 0;
}
