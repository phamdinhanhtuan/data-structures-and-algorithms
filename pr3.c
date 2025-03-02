#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 100
#define Min 0

void nhapSL(int *n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d",n);
}
void mangNgauNhien(int n,int a[]){
    srand(time(NULL));
        for(int i=0; i<n; i++){
            a[i]= rand()%(Max - Min + 1) + Min;
        }
}

void xuatMang(int n,int a[])
{
    printf("Danh sach cac phan tu: \n");
    for(int i=0; i<n; i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}

void swap(int *a,int *b){
    int tam = *a;
        *a = *b;
        *b = tam;
}
void sapXepGiam(int n, int a[])
{
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n ; j++){
            if(a[i] < a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
}

void nhapX(int *x)
{
    printf("Nhap phan tu X can tim: ");
    scanf("%d",x);
}

int binarySearchDes(int n,int a[],int x){
    int l=0, r=n-1, m;
    while(l <= r){
        m = l+(r-l)/2;
        if(a[m] == x){
        return m;
    }else if(a[m] > x){
        l = m+1;
    }else{
        r = m-1;
        }
    }
    return -1;
}
int main()
{
    int n,x;
    int *a = (int*)malloc(n * sizeof(int));
    if(a == NULL){
        printf("Khong du dung luong");
    }
    nhapSL(&n);
    mangNgauNhien(n,a);
    xuatMang(n,a);

    sapXepGiam(n,a), printf("Day so sau khi duoc sap xep\n");
    xuatMang(n,a);
    nhapX(&x);
    int vt = binarySearchDes(n,a,x);
        if(vt == -1){
            printf("Khong tim thay so %d",x);
        }else{
            printf("tim thay %d tai vi tri %d ",x,vt);
        }
    free(a);
return 0;
}
