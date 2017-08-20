/*
Problem statement::
An online game is designed like this:
Many players can play the game, dynamically the players should be included and deleted if they want to quit.
 A list containing the name of player and his/her score should be available so that the players can get to know about their scores and the other player’s scores also. We should be able to traverse the list from first to last and vice-versa.
Identify a suitable data structure, which will help the game designers to perform the above said operations. 
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct linklist
{
	int data;
	char person[100];
	struct linklist* prev;
	struct linklist* next;
};

struct linklist* front=NULL;

struct linklist* create()
{
	struct linklist* temp= new (struct linklist);
	int a; char aa[100];
	cout<<"\n enter the person's name:\t";
	cin>>temp->person;
	cout<<"\n enter the score: \t";
	cin>>a;
	temp->data=a;
	temp->next=NULL;
	temp->prev=NULL;
	return(temp);
}

void insertback ()
{
	struct linklist* temp=new (struct linklist);
	temp=create();
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

void search(char* a)
{
	int counter=0;
	struct linklist* temp= front;
	while(temp!=NULL)
	{
		
		if(strcmp(a, temp->person)==0)
		{
			cout<<"\n\t the score of "<<temp->person <<" is: "<<temp->data<<"\n\t";
			counter=1;
			break;
		}
		temp=temp->next;
	}
	if(counter==0)
	{
		cout<<"\n\t person not found\n\t";
	}
}

void insertfront ()
{
	struct linklist* temp=new (struct linklist);
	temp=create();
	if(front==NULL)
	{
		front=temp;
		return;
	}
	temp->next=front;//******************
	front=temp;
}

void printfront()
{
	struct linklist* temp=front;
	cout<<"___person___\t";
	cout<<"___scores___\n";
	while(temp->next!=NULL)
	{
		cout<<"\t";
		cout<<temp->person<<"\t";
		cout<<"\t";
		cout<<temp->data<<"\n";
		temp=temp->next;
	}
			cout<<"\t";
	cout<<temp->person<<"\t";
			cout<<"\t";
	cout<<temp->data;
}

void printback()
{
	int count=0;
	struct linklist* temp=front;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	
	while(count>0)
	{
	cout<<temp->data<<"\t";
	count--;
	temp=temp->prev;
	}
	cout<<front->data;
}

void deletefront(char *a)//to delete fron the selected position.. 
{	
	struct linklist *temp=front;
	struct linklist *temp1=front;
	int counter=0;
	while(temp1->next!=NULL)
	{
		if(strcmp(temp1->person,a)==0)
		{
			counter=1;
			break;
		}
		temp=temp1;
		temp1=temp1->next;
	}
	if(counter)
	{
	cout<<temp1->person<<"\n\t";
	struct linklist *temp2;
	temp2=temp->prev;
	temp2->next=temp1;
	temp1->prev=temp2;
	free(temp);
	}
}

int main()
{
	int choice=100;
	char aa[100];
	while(choice!=0)
	{
		cout<<"\n\t\t ____WELCOME TO THE SPORTS ASSOCIATION_______ \t\t\n\n";
		cout<<"\tOptions:\n\t 1. ADD THE NEW PLAYER AT END \n\t 2. VIEW ALL SCORES \n\t 3. SEARCH FOR A SCORE \n\t 4. REMOVE PLAYER\n\t 5. ADD THE NEW PLAYER AT THE END \n\t 0. EXIT\n\t";
		cout<<"\n\tenter the operation you want to perform:\n";
		cin>>choice;
		switch(choice)
		{
			case 1: insertback();
			break;
			case 2: printfront();
			break;
			case 3: cout<<"\n\tenter the player's name to be searched: \t "; 
			cin>>aa;
			search(aa);
			break;
			case 4: cout<<"\n\tenter the player to be removed: \t ";
			cin>>aa;
			deletefront(aa);//please check if this function works..
			break;
			case 5: insertfront();
			break;
			case 0: cout<<"\n\t_______________________THANK YOU!!!!___________________________\n\t"; 
			exit;
			break;
			default:
			break;			
		}
		
	}
}
