#include<iostream>
using namespace std;
typedef int elementtype;
struct celltype
{
	elementtype element;
	celltype * next;
 } ;	/*�����*/
 /*���Ա������*/
 typedef celltype * LIST;
 typedef celltype * position;
 
 //��λ��p�ĺ������һ��Ԫ�أ���ֵΪx
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
 
 //ɾ��Ԫ��p�ĺ�һ��Ԫ��
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
 
 LIST first(LIST h)		//h����ͷ�ڵ� 
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
	delete h;	//����������� 
}

int main()
{
	LIST header = new celltype;
	insert(header,3);
	insert(header,5);
	insert(header,8);
	
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
