#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100
#define MIN 0

void nhapSL(int *n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d",n);
}

void nhapMang(int a[],int n)
{
    srand(time(NULL));
    for(int i=0; i<n; i++){
        a[i]= rand()% (MAX - MIN +1)+MIN;
    } 
}

void xuatMang(int a[],int n)
{
    printf("Danh sach cac phan tu: ");
    for(int i=0; i<n; i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}

void interchangeSortInc (int a[],int n)
{
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[j]< a[i]){
                int tam = a[i];
                a[i]=a[j];
                a[j]=tam;
            }
        }
    }
}

void interchangeSortDec(int a[],int n)
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[j] > a[i]){
                int tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }
}

void bubbleSortInc(int a[],int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(a[j] > a[j+1]){
                int tam = a[i];
                    a[i] = a[j+1];
                    a[j+1] = tam;
            }
        }
    }
}

void bubbleSortDec(int a[],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(a[j]< a[j+1]){
                int tam = a[i];
                    a[i] = a[j+1];
                    a[j+1] = tam;
            }
        }
    }
}


int selectionSortInc(int a[],int n)
{
    for(int i=0; i<n-1; i++){
        int min_pos = i;
        for(int j=i+1; j<n; j++){
            if(a[j]< a[min_pos])
                min_pos =j;
        }
        int temp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = temp;
    }
}

int selectionSortDec(int a[],int n)
{
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(a[j]>a[minIndex]){
            minIndex =j;
            }
        }
        int temp = a[i];
            a[i]= a[minIndex];
            a[minIndex] = temp;
    }
}


void insertionSortInc(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; // Chèn key vào đúng vị trí
    }
}

void insertionSortDec(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; // Chèn key vào đúng vị trí
    }
}

int main()
{
    int n;
    nhapSL(&n);
    int *a = (int*)malloc(n * sizeof(int));
    if(a == NULL){
        printf("Khong the cap phat bo nho");
    }

    nhapMang(a,n);
    xuatMang(a,n);

    interchangeSortInc(a,n);
        printf("Day so sau khi sap xep tang:\n ");
        xuatMang(a,n);
    interchangeSortDec(a,n);
        printf("Day so sau khi sap xep giam:\n ");
        xuatMang(a,n);  
    
    bubbleSortInc(a,n);
        printf("Day so sau khi sap xep tang:\n ");
        xuatMang(a,n);
    bubbleSortDec(a,n);
        printf("Day so sau khi sap xep giam:\n ");
        xuatMang(a,n);

    selectionSortInc(a,n);
        printf("Day so sau khi sap xep tang:\n ");
        xuatMang(a,n);
    selectionSortDec(a,n);
        printf("Day so sau khi sap xep giam:\n ");
        xuatMang(a,n);

    insertionSortInc(a,n);
        printf("Day so sau khi sap xep tang:\n ");
        xuatMang(a,n);
    insertionSortDec(a,n);
        printf("Day so sau khi sap xep giam:\n ");
        xuatMang(a,n);

    
    free(a);
return 0;
}
