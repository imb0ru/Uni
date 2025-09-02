#include "linked_list.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void fondiCatena(List_node<int> *&pa,Linked_list<int> &a,List_node<int> *&pb,Linked_list<int> &b, List_node<int>*&pl,Linked_list<int> &l);
bool copia(List_node<int> *&pa,Linked_list<int> &a,List_node<int> *&pb,Linked_list<int> &b);
void copiaCatena(List_node<int> *&pa,Linked_list<int> &a,List_node<int> *&pb,Linked_list<int> &b);
void distribuisci(Linked_list<int> &a, Linked_list<int> &b, Linked_list<int> &l);
int merge(Linked_list<int> &a, Linked_list<int> &b, Linked_list<int> &l);
void ordinamento_naturale(Linked_list<int> &l);


void fondiCatena(List_node<int> *&pa,Linked_list<int> &a,List_node<int> *&pb,
				Linked_list<int> &b, List_node<int>*&pl,Linked_list<int> &l)
{
	bool finecatena;
	do{	
		if (a.read(pa) < b.read(pb))
		{
			finecatena=copia(pa, a, pl, l);
			if (finecatena)
				copiaCatena (pb, b, pl, l);
		}
		else
		{
			finecatena=copia(pb, b, pl, l);
			if (finecatena)
				copiaCatena(pa, a, pl, l);
		}
	}while(!finecatena);
}

bool copia(List_node<int> *&pa,Linked_list<int> &a,List_node<int> *&pb,Linked_list<int> &b)
{
	bool finecatena;	
	int elemento = a.read(pa);
	b.insert(elemento,b.next(pb));
	a.erase(pa);
	pa = a.next(pa);
	pb = b.next(pb);
	if (a.end(pa))
		finecatena=true;
	else
		finecatena = (elemento > a.read(pa));
	return finecatena;

}

void copiaCatena(List_node<int> *&pa,Linked_list<int> &a,List_node<int> *&pb,Linked_list<int> &b)
{
	bool finecatena;
	do{
		finecatena= copia(pa,a,pb,b);
	}while(!finecatena);
}

void distribuisci(Linked_list<int> &l,Linked_list<int> &a, Linked_list<int> &b)
{

	List_node <int> *pl = l.begin();
	List_node <int> *pa = a.begin();
	List_node <int> *pb = b.begin();
	do{
		copiaCatena(pl, l, pa, a);
		if (!l.end(pl))
			copiaCatena(pl, l, pb, b);
	}while(!l.end(pl));
}

int merge(Linked_list<int> &a, Linked_list<int> &b, Linked_list<int> &l)
{
	int numero_catene=0;
	List_node <int> *pl = l.begin();
	List_node <int> *pa = a.begin();
	List_node <int> *pb = b.begin();
	while(!a.end(pa) && !b.end(pb))
	{
		fondiCatena(pa,a,pb,b,pl,l);
		numero_catene++;
	}
	while (!a.end(pa))
	{
		copiaCatena(pa, a, pl, l);
		numero_catene++;
	}
	while (!b.end(pb))
	{
		copiaCatena(pb, b, pl, l);
		numero_catene++;
	}
	return numero_catene;
}


void ordinamento_naturale(Linked_list<int> &l)
{
	int numero_catene;
	do{
		Linked_list<int> a;
		Linked_list<int> b;
		distribuisci(l,a,b);
		numero_catene=merge(a,b,l);
	}while(!(numero_catene==1));
	cout << l;
}

int main(){
	Linked_list<int> l;
	for(int i=0; i<5;i++)
	{
		int n;
		cout << "Inserisci numero " ;
		cin >> n;
		l.insert(n,l.begin());	
	}
	ordinamento_naturale(l);
	getchar();		
	getchar();
	return 0;
}
