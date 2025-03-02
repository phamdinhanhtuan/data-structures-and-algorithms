#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100
void nhapSL(int *n)
{
    do{
    printf("Nhap so luong phan tu: ");
    scanf("%d",n);
    }while(*n<=0 || *n>Max);
}

void nhapMang(int a[],int n)
{
   for(int i=0; i<n; i++){
        printf("Nhap phan tu thu a[%d]: ",i+1);
        scanf("%d",&a[i]);
   }
}

void xuatMang(int a[],int n)
{
    printf("Danh sach phan tu\n");
    for(int i=0; i<n; i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}

void NhapX(int *x){
    printf("Phan tu X can tim la: ");
    scanf("%d",x);
}

int LinearSearch(int a[],int n,int x){
    for(int i=0; i<n; i++){
        if(a[i] == x)
            return i;
    }
    return -1;
}

void SapXepTang(int n,int a[],int x)
{
    for(int i=0; i< n-1; i++){
        for(int j=i+1; j<n;j++){
            if(a[i]>a[j]){
                int tam = a[i];
                a[i] = a[j];
                a[j] = tam; 
            }
        }
    }
return;
}

int BinarySearch(int n,int a[],int x){
    int d=0,c= n-1, g;
    while(d <= c)
    {
        g = d+(c-d)/2;
        if(a[g] == x){
            return g;
        }else if(a[g] < x){
             d = g+1;
        }else{
        c = g-1;
       }
    }
    return -1;
}
int main()
{
    int n,x;
   
    nhapSL(&n);
    int *a = (int*)malloc(n * sizeof(int));
    nhapMang(a,n);
    xuatMang(a,n);
    
    NhapX(&x);
    int vt = LinearSearch(a,n,x);
    if (vt == -1) {
    printf("Khong tim thay!\n");
} else {
    printf("Tim thay %d tai vi tri %d\n", x, vt);
}

    SapXepTang(n,a,x);
    printf("\nDay so sau khi sap xep:\n ");
    xuatMang(a,n);
    NhapX(&x);
    int ViTri = BinarySearch(n,a,x);
    if(ViTri == -1){
        printf("Khong tim thay!");
    }else
    {
        printf("Tim thay %d tai vi tri %d: ",x,ViTri);
    }
free(a);
return 0;
}
