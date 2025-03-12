#include<stdio.h>
#include<stdlib.h>

void nhapSL(int *n)
{
    printf("Nhap so luong: ");
    scanf("%d",n);
}

void nhapMang(int a[],int n)
{
    for(int i=0; i<n; i++){
        printf("\nNhap phan tu thu %d: ",i+1);
        scanf("%d",&a[i]);
    }
}

void xuatMang(int a[],int n,int step)
{

    printf("Buoc %d: ",step);
    for(int i=0; i<n; i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}

void selectionSortInc(int a[],int n)
{
    for(int i=0; i<n-1; i++){
        int min =i;
        for(int j=i+1; j<n; j++){
            if(a[j] < a[min]){
            min = j;
            }
        }
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        
          xuatMang(a,n,i+1);
    }
}

void selectionSortDec(int a[],int n)
{
    for(int i=0; i<n-1; i++){
        int min_pos = i;
        for(int j=i+1; j<n ; j++){
            if(a[j] > a[min_pos]){
                min_pos = j;
            }
        }

            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        
          xuatMang(a,n,i+1);
    }
}
int main()
{
    int n;
    nhapSL(&n);
    int *a = (int*)malloc(n * sizeof(int));
    if(a == NULL){
        printf("Khong the cap phat bo nho!");
    }

    nhapMang(a,n);
    xuatMang(a,n,0);
    selectionSortInc(a,n);
    selectionSortDec(a,n);
free(a);
return 0;
}
