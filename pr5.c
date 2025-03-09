#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
#define MIN 0
void nhapSL(int *n)
{
        printf("Nhap so luong phan tu: ");
        scanf("%d",n);
}

void mangNgauNhien(int n,int a[]){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        a[i]= rand()%(MAX - MIN +1)+MIN;
    }
}

void xuatMang(int n,int a[])
{
    printf("Danh sach cac phan tu: ");
    for(int i=0; i<n; i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}

int selectionSortASC(int n,int a[])
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

int selectionINC(int n,int a[])
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

int main()
{
    int n;
    nhapSL(&n);
    int *a = (int*)malloc(n * sizeof(int));
    if(a == NULL){
        printf("Khong the cap phat bo nho");
    }
    mangNgauNhien(n,a);
    xuatMang(n,a);

    selectionSortASC(n,a);
    printf("\nMang tang dan sau khi sap xep:\n ");
    xuatMang(n,a);

    selectionINC(n,a);
    printf("\nMang giam dan sau khi sap xep:\n ");
    xuatMang(n,a);

    free(a);
return 0;
}
