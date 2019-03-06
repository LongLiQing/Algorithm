#include<iostream>
#define maxsize 100
using namespace std;
typedef int elementtype;
typedef struct
{
	elementtype element;
	int next;
 } spacestr;
 spacestr SPACE[maxsize];
 
 typedef int position,cursor;
 cursor available;
 
 void initialize()
 {
 	available = 0;
 	for(int i = 0;i<maxsize-1;i++)			//ע�� 
 		SPACE[i].next = i+1;
 	SPACE[maxsize-1].next = -1;
 }
 
 //�ӿ��г���ȡһ���ڵ� 
 int get_node()
 {
 	int ans = SPACE[available].next;
 	if(ans != -1)
 		SPACE[available].next = SPACE[ans].next;
 	return ans;
 }
 
 //����г��м�һ���ڵ� 
 void put_node(cursor k)
 {
 	SPACE[k].next = SPACE[available].next;
 	SPACE[available].next = k;
 }
 
 //��λ��pd�ĺ������һ���ڵ�
 void insert(position p,elementtype x)
 {
 	int q = get_node();
 	if(q == -1)
 	{
 		cout<<"ERROR!"<<endl;
 		return;
	 }
	SPACE[q].element = x;
	SPACE[q].next = SPACE[p].next;
	SPACE[p].next = q;
  } 
 
 //ɾ��λ��p֮��Ľڵ�
 void Delete(position p)
 {
 	position q = SPACE[p].next;
 	if(q == -1)
 	{
 		cout<<"ERROR!"<<endl;
 		return;
	 }
 	SPACE[p].next = SPACE[q].next;
 	put_node(q);
  } 
  
  
 int main()
 {
 	initialize();
 	cursor L = get_node();
 	SPACE[L].next = -1;
 	insert(L,3);
 	insert(L,5);
 	insert(L,7);
 	cursor M = get_node();
 	SPACE[M].next = -1;
 	insert(M,2);
 	insert(M,5);
 	cursor t = L;
 	while(t!=-1)
 	{
 		cout<<SPACE[t].element;
 		t = SPACE[t].next;
	 }
 	return 0;
 }
