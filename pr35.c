
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct mathang
{
	char mahang [11];
	char Tenhang [41];
	int soluong;
}Mahang;

typedef struct node
{
	Mahang data;
	struct node* next;
}Node;

void khoidau (Node* &phead)
{
	phead = NULL;
}

Node* taonut (Mahang x)
{
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

void NhapMatHang (Mahang &a)
{
	printf("Nhap ma hang: ");
	scanf("%s",a.mahang);
	printf("Nhap ten hang: ");
	fflush(stdin);
	gets(a.Tenhang);
	printf("Nhap so luong: ");
	scanf("%d",&a.soluong);
}

void XuatMaHang (Mahang a)
{
	printf("Ma hang : %s\n",a.mahang);
	printf("Ten hang: %s\n",a.Tenhang);
	printf("So luong: %d\n",a.soluong);
}

void themdau (Node* &phead, Mahang a)
{
	Node* p = taonut(a);
	if(phead == NULL)
	{
		phead = p;
	}
	else
	{
		p->next = phead ;
		phead = p;
	}
}

void themcuoi (Node* &phead, Mahang a)
{
	Node* p = taonut(a);
    if (phead == NULL) 
    {
        phead = p;
    }
    else
    {
        Node* temp = phead;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = p; 
    }
}

void NhapDS (Node* &phead)
{
	int n;
	printf("Nhap so luong mat hang: ");
	scanf("%d",&n);
	Mahang a;
	for(int i=1; i<=n ; i++)
	{
		printf("Mat hang [%d]: \n",i);
		NhapMatHang(a);
	//	themdau(phead,a);
		themcuoi(phead,a);
		printf("\n");
	}
}

void XuatDS (Node* phead)
{
	printf("Xuat mat hang: \n");
	for(Node* p=phead; p!=NULL ; p=p->next)
	{
		XuatMaHang(p->data);
	}
}

void NhapX (char x[])
{
	printf("\nNhap ma x: ");
	scanf("%s",x);
}

//int TimX (Node* phead, char x[])
//{
//	int vtri = 0;
//	for(Node* p = phead ; p!=NULL ; p=p->next , vtri++)
//	{
//		if(strcmp(p->data.mahang,x)==0)
//		{
//			return vtri;
//		}
//	}
//	return -1;
//	
//}

Node* TimX (Node* phead, char x[])
{
	for(Node* p = phead ; p!=NULL ; p=p->next)
	{
		if(strcmp(p->data.mahang,x)==0)
		{
			return p;
		}
	}
	return NULL;
}

void ThemSau (Node* &phead, Mahang a)
{
	Node* tam = taonut(a);
	tam->next = phead->next;
	phead->next = tam;
}

void themYsauZ (Node* &phead, char x[])
{
	Node* kq = TimX(phead,x);
	if(kq==NULL)
	{
		printf("\nKo tim thay");
	}
	else
	{
		Mahang y;
		NhapMatHang(y);
		printf("\n");
		ThemSau(kq,y);
	}
}


void XoaDau (Node* &phead)
{
	if(phead == NULL)
	{
		printf("Danh sach rong khong co gi de xoa");
		return ;
	}
	Node* tam = phead;
	phead = phead->next;
	free(tam);
}

void XoaToanBoDS (Node* &phead)
{
	Node* tam = phead;
	while(tam != NULL)
	{
		Node* NutMoi = tam->next;
		free(tam);
		tam = NutMoi;
	}
	phead = NULL;
}

void XoaMatHangX (Node* &phead)
{
	char x[11];
	printf("\nNhap ma hang X muon xoa: ");
	scanf("%s",x);
	
    while (phead != NULL && strcmp(phead->data.mahang, x) == 0) 
	{
        Node* temp = phead;
        phead = phead->next;
        free(temp);
    }
	
    for (Node* p = phead; p != NULL && p->next != NULL; p = p->next) 
	{
        if (strcmp(p->next->data.mahang, x) == 0) 
		{
            Node* temp = p->next;
            p->next = p->next->next;
            free(temp);
            return;
        }
    }
}


void SapXepTangTheoTenHang (Node* phead)
{
	for(Node* i = phead ; i->next!=NULL ; i=i->next)
	{
		for(Node* j = i->next ; j!=NULL ; j=j->next)
		{
			if(strcmp(i->data.Tenhang,j->data.Tenhang)>0)
			{
				Mahang tam = i->data;
				i->data = j->data;
				j->data = tam;
			}
		}
	}
	
}
int main ()
{
	Node* p;
	Mahang a;
	khoidau(p);
	NhapDS(p);
	XuatDS(p);
//	printf("\n");
		
		
//	printf("\nXoa mat hang dau danh sach: \n");
//	XoaDau(p);
//	XuatDS(p);
	
//	printf("\nXoa toan bo danh sach: \n");
//	XoaToanBoDS(p);
//	XuatDS(p);

//	printf("\nXoa ma da nhap: \n");
//	XoaMatHangX(p);
//	XuatDS(p);
	printf("\nSap Xep tang theo ten hang: \n");
	SapXepTangTheoTenHang(p);
//	XuatDS(p);
	
	char x[11];
	printf("\nNhap ma truoc ma muon them sau:\n");
	NhapX(x);
	themYsauZ(p,x);
	XuatDS(p);
	
	return 0;
}
