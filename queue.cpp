#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int a;
	struct node *next; 
};

struct node* front=NULL;
struct node* rear=NULL;

struct node* createnode(int n)
{
struct node* temp=new node;
temp->a=n;
temp->next=NULL;	
return(temp);
}

void inserthead(int n)
{
	struct node* temp=new node;
	temp=createnode(n);
	if(front==NULL && rear==NULL)
	{
		front=temp;
		rear=temp;
		cout<<"\n"<<n<<" is inserted at front \n";
		return;
	}
	struct node* tempw=front;
	front=temp;
	front->next=tempw;
	cout<<"\n"<<n<<" is inserted at front \n";
}
void insertf(int n)
{
	struct node* temp=new node;
	temp=createnode(n);
	if(front==NULL && rear==NULL)
	{
		front=temp;
		rear=temp;
		cout<<"\n"<<n<<" is inserted at back\n";
		return;
	}
	rear->next=temp;
	rear=temp;
	cout<<"\n"<<n<<" is inserted at back\n";
} 

void print()
{
	struct node* temp=front;
	cout<<"\n";
	while(temp->next!=NULL)
	{
		cout<<temp->a<<"\t";
		temp=temp->next;
	}
	cout<<temp->a<<"\t"<<"\n";
}

int chk()
{
	if(front==NULL && rear==NULL)
	{
		cout<<"\n\t no elements present in the list to delete \n\t";
		return(0);
	}
	else
	{
		return(1);
	}
}
void deletend()
{
	{
	struct node* temp=front;
	struct node* temp2=NULL;	
	while(temp->next!=NULL)
	{
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=NULL;
	rear=temp2;
	cout<<"\n\t"<<temp->a<<"is free'd!!!\n\t";
	free(temp);
	}
}

void deletefront()
{
	if(chk()==1)
	{
	struct node* temp=front->next;
	struct node* temp2=front;
	front=temp;
	cout<<"\n\t"<<temp2->a<<"is free'd!!!\n\t";
	free(temp2);	
	}
}
void deletepos(int n)
{
	int x=n-1;
	if(chk()==1)
	{
	struct node* temp=front;
	struct node* temp2;	
	struct node* temp3;
	while(x!=0)
	{
		temp2=temp;
		x=x-1;
		temp=temp->next;
	}
	temp3=temp->next;
	temp2->next=temp3;
    cout<<"\n\t"<<temp->a<<"is free'd from position "<<n<<"!!!\n\t";
	free(temp);
	}
}
int main()
{
	int e, c2;
	int choice=100;
	while(choice!=0)
	{
		cout<<"\n\t\t________link-list___________\n \tenter the choice:\n \t1. insert\n\t 2. print\n\t3. delete\n\t4. exit\n";
		cin>>choice;
		switch(choice)
		{
		case 1: cout<<"\n\t insert the element";
		cin>> e;
		cout<<"\n\t do you want to insert it in front or back? \n\t 1-front 2-back\n\t";
		cin>>c2;
		if(c2==1)
		{
			inserthead(e);
			break;
		}
		else
		insertf(e);
		break;
		case 2: print();
		break;
		case 3: cout<<"\n\t delete at (enter the choice)\n\t 1.front \n\t 2.back \n\t 3. i'll tell where to delete \n\t";
		cin>>c2;
		if(c2==1)
		{
			deletefront();
			break;
		}
		else if(c2==2)
		{
			deletend();
			break;
		}
		else if(c2==3)
		{
			cout<<"\n\t enter the postion at which you wanna delete\n\t";
			cin>>e;
			deletepos(e);
			break;
		} 
		else
		break;
		case 4: exit(0);
		default: break;
		}		
	}
}
