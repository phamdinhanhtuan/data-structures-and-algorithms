#include<stdio.h>
#include<stdlib.h>
void nhapSL(int *n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d",n);
}

void nhapMang(int n,int a[])
{
    for(int i=0; i<n; i++){
        printf("Nhap phan tu thu a[%d]: ",i+1);
        scanf("%d",&a[i]);
    }
}

void xuatMang(int n,int a[])
{
    printf("Danh sach cac phan tu ");
    for(int i=0; i<n; i++){
        printf("%d ",i+1);
    }
    printf("\n");
}

void timX(int *x)
{
    printf("Nhap gia tri X can tim: ");
    scanf("%d",x);
}
int viTriDauTien(int n,int a[],int x){
    for(int i=0; i<n; i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}

int main()
{
    int n,x;
    nhapSL(&n);
    int *a= malloc(n * sizeof(int));
    if( a== NULL){
        printf("Khong du bo nho !\n");
        return 1;
    }
    nhapMang(n,a);
    xuatMang(n,a);
    timX(&x);
    int viTri=viTriDauTien(n,a,x);
    if(viTri == 1){
        printf("Khong tim thay %d trong mang\n",x);
    }else{
        printf("Vi tri dau tien cua %d trong mang la: %d\n",x,viTri+1);
    }
return 0;
}
