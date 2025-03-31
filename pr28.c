#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    data,
    Node* next;
};
typedef struct Node* node;
// cap phat dong mot node moi 
node makeNode(int x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// kiem tra rong
bool empty(node a)
{
    return a == NULL
}

//dem  xem ben trong ham co bao nhiu phan tu
int size(node a){
    int count=0;
    while(a != NULL)
    {
        count++;
        a = a->next;//gan dia chi cua node tiep theo cho node hien tai 
            //cho node hien tai nhanh sang node tiep theo
    }
    return count
}
// them 1 phan tu vao dau cua dslk
void themDau(node *a,int x)
{
    node tmp = makeNode(x)// de xin cap phat node moi
    if(a == NULL){//kiem tra rong
        a = temp;
    }else{
        temp->next = a; //tu temp se tro nguoc ve next cua thang a,de thg temp 
        //no se lua dia chi cua phan tu dau tien o hien tai
        a = temp; //a cap nhat lai thg temp
    }
}
//them 1 phan tu vao cuoi 
void themCuoi(node *a,int x)
{
    node tmp = makeNode(x);
    if(a != NULL){
        a = tmp;
    }
    else{
        node p =a ;
        while(p -> next != NULL){// duyet tu p den NULL,de kiem tra
            p = p->next;// p se qua nha cua tung thag
        }
        p->next = tmp// de cho thg next cua p tro vao temp ,la vi tri cuoi hien tai
    }
}

//them 1 phan tu vao giua
void themGiua(node *a,int x)
{
    int n = size(a);
    if(pos <= 0 || pos > n+1){
        printf("Vi tri chen khong hop le!");
    }else if(n ==1)
    {
        themDau(a,n);
        return;
    }
    else if(n == pos+1)
    {
        themCuoi(a,n);
        return;
    }
    node p = a;
    for(int i=1; i<pos-1; i++){
        p = p->next;
    }
    node tmp = nodeMake(a);
    tmp -> next = p-> next;
    p-> next = tmp;
}

// xoa dau
void xoaDau(node *a,int x)
{
    if(a != Null){
        a = a->next
    }
}
int main()
{
    node* head = NULL
}
