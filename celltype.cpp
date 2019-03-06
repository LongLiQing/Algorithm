#include<iostream>
using namespace std;
typedef int elementtype;
struct celltype
{
	elementtype element;
	celltype * next;
 } ;	/*结点型*/
 /*线性表的类型*/
 typedef celltype * LIST;
 typedef celltype * position;
 
 //在位置p的后面插入一个元素，其值为x
 void insert (position p, elementtype x)
 {
 
	LIST q = new celltype;
	if(q==NULL)
	{
	cout<<"ERROR"<<endl;
	return;
	}
	q->element = x;
	q->next = p->next;
//	p->next = p->next;
	p->next = q;
 }
 
 //删除元素p的后一个元素
 void Delete(position p)
 {
	if(p->next == NULL)
	{
	cout<<"ERROR!"<<endl;
	return;
	}

	LIST q = p->next;
	p->next =p->next->next;	//p->next = q->next;
	delete q;
 }
 
 LIST first(LIST h)		//h代表头节点 
 {
 	return h->next;
 }
 

 LIST end(LIST h)
 {
 	LIST temp = h;
 	while(1)
 	{
 		if(temp->next == NULL)
 			break;
 		temp = temp->next;
	 }
	 return temp;
 }
 
 LIST next(position p)
 {
 	return p->next;
 }
 
 LIST previous(LIST h,position p)
 {
 	LIST temp = h;
 	while(1)
 	{
 		if(temp->next == p)
 			break;
 		temp = temp->next;
	 }
	 return temp;
 }
 
void makenull(LIST h)
{
	//	while(h->next!=NULL)
	//	Delete(h);
	LIST p;
	while(h->next != NULL)
	{
		p = h->next;
		h->next = p->next;
		delete p;
	}
	delete h;	//将整个表清空 
}

int main()
{
	LIST header = new celltype;
	insert(header,3);
	insert(header,5);
	insert(header,8);
	
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
