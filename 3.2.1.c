#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm sinh mảng ngẫu nhiên
void generateArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Hàm xuất mảng ra màn hình
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm sắp xếp mảng tăng dần bằng Interchange Sort
void interchangeSortAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng giảm dần bằng Interchange Sort
void interchangeSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng tăng dần bằng Bubble Sort
void bubbleSortAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng giảm dần bằng Bubble Sort
void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    generateArray(arr, n);
    printf("Mang ngau nhien: ");
    printArray(arr, n);

    interchangeSortAsc(arr, n);
    printf("Mang sap xep tang dan bang Interchange Sort: ");
    printArray(arr, n);

    interchangeSortDesc(arr, n);
    printf("Mang sap xep giam dan bang Interchange Sort: ");
    printArray(arr, n);

    bubbleSortAsc(arr, n);
    printf("Mang sap xep tang dan bang Bubble Sort: ");
    printArray(arr, n);

    bubbleSortDesc(arr, n);
    printf("Mang sap xep giam dan bang Bubble Sort: ");
    printArray(arr, n);

    return 0;
}
