#include<iostream>
#define maxlength  100
using namespace std;
typedef int elementtype;
struct List{
	elementtype element[maxlength];
	int last;
};

typedef int position;

void Insert(elementtype x,position p,List & L)
{
	if(L.last==maxlength-1 || p<1 || p>L.last+1)
	cout<<"error!"<<endl;
	position i;
	for(i=L.last;i>=p;i--)
	{
		L.element[i+1]=L.element[i];
	}
	L.element[p]=x;
	L.last++;
}

position Locate(elementtype x,List &L)
{
	position q;
	for(q=1;q<=L.last;q++)
	{
		if(x==L.element[q])
		return q;
	}
}

elementtype Retrieve(position p,List &L)
{
	return L.element[p];
}

void Delete(position p,List &L)
{
	position i;
	for(i=p;i<=L.last-1;i++)
		L.element[i]=L.element[i+1];
	L.last--;
}


int main()
{
	List a;
	Insert(3,1,a);
	Insert(4,2,a);
	cout<<a.last<<endl;
	return 0;
}
