
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Phong
{
	int maphong;
	char tenphong [31];
	int tinhtrang;
}P;

typedef struct node
{
	P data;
	struct node* next;
}Node;

void khoitao (Node* &phead)
{
	phead = NULL;
}

Node* taonut (P a)
{
	Node* p = new Node;
	p->data = a;
	p->next = NULL;
	return p;
}

void Themcuoi (Node* &phead, P a)
{
	Node* p = taonut(a);
    if (phead == NULL) 
    {
        phead = p;
    }
	else
	{
		Node* tam = phead;
		while(tam->next != NULL)
		{
			tam=tam->next;
		}
		tam->next = p;
	}
}

void Nhap1P (P &a)
{
	printf("Ma phong: ");
	scanf("%d",&a.maphong);
	printf("Ten phong:");
	fflush(stdin);
	gets(a.tenphong);
	do
	{
		printf("Tinh trang(0(co khach) ||1(ko co khach)): ");
		scanf("%d",&a.tinhtrang);
	}while(a.tinhtrang < 0 || a.tinhtrang > 1);
}

void NhapDS (Node* &phead)
{
	int n;
	P a;
	printf("Nhap so luong phong: ");
	scanf("%d",&n);
	for(int i=1 ; i<=n ; i++)
	{
		printf("Phong [%d]: \n",i);
		Nhap1P(a);
		Themcuoi(phead,a);
		printf("\n");
	}
}

void Xuat1P (P a)
{
	printf("Ma phong  : %d\n",a.maphong);
	printf("Ten phong : %s\n",a.tenphong);
	printf("Tinh trang: %s\n",a.tinhtrang == 1 ? "Da co nguoi" : "Phong trong");
}

void XuatDS (Node* phead)
{
	for(Node* p = phead ; p!=NULL ; p=p->next)
	{
		Xuat1P(p->data);
	}
}

Node* TimPhongDauTienChong (Node* phead)
{
	for (Node* p = phead; p != NULL; p = p->next)
    {
        if (p->data.tinhtrang == 0)
        {
			return p;   
        }
    }
    return NULL;
}

void XuatPhongTrongdautien (Node* phead)
{
	Node* tim = TimPhongDauTienChong(phead);
	if(tim == NULL)
	{
		printf("Khong co phong trong dau tien");
	}
	else
	{
		printf("Phong trong dau tien la: \n");
		Xuat1P(tim->data);
	}
}

int DemSoLuongPhongCoKhach (Node* phead)
{
	Node* tam = phead;
	int dem = 0;
	while( tam != NULL)
	{
		if(tam->data.tinhtrang == 1)
		{
			dem++;
		}
		tam = tam->next;
	}
	return dem;
}

void ThemMotPhongCuoi(Node* &phead)
{
    P a;
    printf("\nNhap thong tin phong can them vao cuoi danh sach:\n");
    Nhap1P(a);
    Themcuoi(phead,a);
}

void SapXeptangTheoMaPhong (Node* phead)
{
	for(Node* i = phead ; i->next != NULL ; i=i->next)
	{
		for(Node* j = i->next ; j!=NULL ; j=j->next)
		{
			if(i->data.maphong > j->data.maphong)
			{
				P tam = i->data;
				i->data = j->data;
				j->data = tam;
			}
		}
	}
}


int main ()
{
	Node* p;
	khoitao(p);
	NhapDS(p);
	XuatDS(p);
	XuatPhongTrongdautien(p);
	int Dem = DemSoLuongPhongCoKhach(p);
	printf("\nSo phong da co khach: %d",Dem);
	ThemMotPhongCuoi(p);
	SapXeptangTheoMaPhong(p);
	XuatDS(p);
	return 0;
}
