#include <stdio.h>

void xuatDS(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    int tam = *x;
    *x = *y;
    *y = tam;
}

// Interchange Sort
void IS(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
        printf("Sau buoc %d: ", i + 1);
        xuatDS(a, n);
    }
}

// Bubble Sort
void BS(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
        printf("Sau buoc %d: ", i + 1);
        xuatDS(a, n);
    }
}

// Selection Sort
void SS(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(&a[i], &a[min_idx]);
        printf("Sau buoc %d: ", i + 1);
        xuatDS(a, n);
    }
}

// Insertion Sort
void InsS(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        printf("Sau buoc %d: ", i);
        xuatDS(a, n);
    }
}

int main() {
    int a[] = {3, 22, 45, 18, 23, 7, 6, 11};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Interchange Sort:\n");
    IS(a, n);
    
    // Reset array for next sort
    int b[] = {3, 22, 45, 18, 23, 7, 6, 11};
    printf("\nBubble Sort:\n");
    BS(b, n);
    
    // Reset array for next sort
    int c[] = {3, 22, 45, 18, 23, 7, 6, 11};
    printf("\nSelection Sort:\n");
    SS(c, n);
    
    // Reset array for next sort
    int d[] = {3, 22, 45, 18, 23, 7, 6, 11};
    printf("\nInsertion Sort:\n");
    InsS(d, n);

    return 0;
}
