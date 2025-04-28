#include<stdio.h>

void nhapSL(int *n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d",n);
}

void nhapDS(int n,int a[])
{
    for(int i=0; i<n; i++){
        printf("nhap phan tu thu: ");
        scanf("%d", &a[i]);
    }
}

void xuatDS(int n,int a[])
{
    printf("Danh sach cac phan tu");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}

int timTuanTu(int n,int a[],int x)
{
    for(int i=0; i<n; i++){
        if(a[i] == x)
            return i;
    }
    return -1;
}

void nhapX(int *x)
{
    printf("Nhap gia tri can tim x: ");
    scanf("%d",x);
}

int main()
{
    int n,x;
    int a[100];
        nhapSL(&n);
        nhapDS(n,a);
        xuatDS(n,a);

    nhapX(&x);
    int kq= timTuanTu(n,a,x);
        if(kq != -1){
            printf("Tim thay ket qua tai vi tri:%d ",kq);
        }else
        {
            printf("Khong tim thay! ");
        }
    return 0;
}
