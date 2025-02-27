#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 100
#define Min 0

void mangNgauNhien(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand()% (Max - Min +1)+ Min;
    }
}


void XuatMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void interchangeSortTang(int arr[], int n) {
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


void interchangeSortGiam(int arr[], int n) {
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


void bubbleSortTang(int arr[], int n) {
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


void bubbleSortGiam(int arr[], int n) {
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

    mangNgauNhien(arr, n);
    printf("Mang ngau nhien: ");
    XuatMang(arr, n);

    interchangeSortTang(arr, n);
    printf("Mang sap xep tang dan bang Interchange Sort Tang: ");
    XuatMang(arr, n);

    interchangeSortGiam(arr, n);
    printf("Mang sap xep giam dan bang Interchange Sort Giam: ");
    XuatMang(arr, n);

    bubbleSortTang(arr, n);
    printf("Mang sap xep tang dan bang Bubble Sort Tang: ");
    XuatMang(arr, n);

    bubbleSortGiam(arr, n);
    printf("Mang sap xep giam dan bang Bubble Sort Giam: ");
    XuatMang(arr, n);

    return 0;
}
