#include<iostream>
#include<stdlib.h>
using namespace std;

struct linklist
{
	int data;
	struct linklist* prev;
	struct linklist* next;
};

struct linklist* front=NULL;

struct linklist* create(int a)
{
	struct linklist* temp= new (struct linklist);
	temp->data=a;
	temp->next=NULL;
	temp->prev=NULL;
	return(temp);
}

void insertback (int a)
{
	struct linklist* temp=new (struct linklist);
	temp=create(a);
	struct linklist* tempo=front;
	if(front==NULL)
	{
		front=temp;
		return;
	}
	while(tempo->next!=NULL)
	{
		tempo=tempo->next;
	}
	tempo->next=temp;
	temp->prev=tempo;
}

void insertfront (int a)
{
	struct linklist* temp=new (struct linklist);
	temp=create(a);
	if(front==NULL)
	{
		front=temp;
		return;
	}
	temp->next=front;//******************
	front=temp;
	/*
	struct linklist* temp=front;
	cout<<temp->data<<"\n";
	while(temp->next!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<temp->data;
	*/
}

void printfront()
{
	struct linklist* temp=front;
	cout<<temp->data<<"\n";
	while(temp->next!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<temp->data;
}

void printback()
{
	int count=0;
	struct linklist* temp=front;
	cout<<temp->data<<"\n";
	while(temp->prev!=NULL)
	{
		temp=temp->prev;
		count++;
	}
	while(count>0)
	{
	cout<<temp->data;
	count--;
	temp=temp->prev;
	}
}

void deletefront()
{
	struct linklist* temp=front;
	front=front->next;
	delete(temp);
}

int main()
{
	insertfront(2);
	insertfront(9);
	insertback(1);
	insertback(4);
	insertback(5);
	printback();
	cout<<"\n";
	printfront();
	cout<<"\n";
	deletefront();
	cout<<"\n";
	printback();
	cout<<"\n";
	printfront();
}
