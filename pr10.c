#include<stdio.h>
#include<stdlib.h>
void nhapSL(int *n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d",n);
}

void nhapMang(int a[],int n)
{
    for(int i=0; i<n; i++){
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d",&a[i]);
    }
}

void xuatMang(int a[],int n,int step)
{
     printf("\nBuoc %d:",step);
    for(int i=0; i<n; i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}

void sapXep(int a[],int n)
{
    for(int i=0; i<n-1; i++){
        for(int j=i+1 ; j<n; j++){
            if(a[i] > a[j]){
            int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        xuatMang(a, n, i+1); 
    }
    printf("\n");
}
int main()
{
int n,step;
nhapSL(&n);
int *a = (int*)malloc(n * sizeof(int));
if(a == NULL){
    printf("Khong the cap phat bo nho!");
}
nhapMang(a,n);
xuatMang(a,n,0);
sapXep(a,n);
free(a);
return 0;
}
