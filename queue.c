#include<stdio.h>
#include<conio.h>

struct Qnode
{
	int data;
	struct Qnode* next;
};

struct Qnode* front=NULL;
struct Qnode* rear=NULL;

struct Qnode* newll(int k)
{
	struct Qnode* temp=(struct Qnode*)malloc(sizeof(struct Qnode));
	temp->data=k;
	temp->next=NULL;
	return(temp);
}
struct Qnode* enqueue1(int a)
{
	struct Qnode* temp=(struct Qnode*)malloc(sizeof(struct Qnode));
	temp=newll(a);
	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}
struct Qnode* enqueue2(int a, int pos)
{
	struct Qnode*temp=(struct Qnode*)malloc(sizeof(struct Qnode));
	temp=newll(a);
	if(front==NULL && rear==NULL)
	{
		rear=front=temp;
		return;
	}
	struct Qnode* dem=front;
	int mid=pos-1;
	while(mid!=0)
	{
		mid--;
		dem=dem->next;
	}
	temp->next=dem->next;
	dem->next=temp;
	printf("\n item inserted at pos %d", pos);
}
void print()
{
	struct Qnode* a=front;
	while(a!=NULL)
	{
		printf("%d\n", a->data);
		a=a->next;
	}
	printf("----------------\n");
}
void dequeue()
{
	struct Qnode* temp= front;
	if(front==NULL)
	{
		printf("empty");
		return;
	}
	if(front==rear)
	{
		front=rear=NULL;
		return;
	}
	else
	{
		front=front->next;
		free(temp);
	}
}
/*void enqueue3(int k)
{
	struct Qnode* temp=(struct node*)malloc(sizeof(struct Qnode));
	temp=newll(k);
	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
		return;
	}
	head->next=temp;
	temp->next=front;
}
*/
int main()
{
int choice=100, x, pos;
while(choice!=0)
{
printf("\n \t \t------------ QUEUE ----------------\n \t enter the choice: \n \t 1. insert at the end \n \t 2. delete at front \n \t 3. print \n \t 4. insert at the middle \n \t 5.Insert in the front \n \t 0. EXIT\n\t");
scanf("%d", &choice);
switch(choice)
{
	case 1: printf("\n enter the element you want to enter \t");
			scanf("%d", &x);
			enqueue1(x);
			break;
	case 2: dequeue();
			break;
	case 3: print();
			break;
	case 4: printf("\n enter the position you want to enter the element at \t");
			scanf("%d", &pos);
			printf("\n enter the element you want to enter \t");
			scanf("%d", &x);
			enqueue2(x, pos);
			break;
/*	case 5: printf("\n enter the element you want to enter \t");
			scanf("%d", &x);
			enqueue3(x);
			break;
*/
	default: break;
}

}
if(choice==0)
{
	printf("\n\n -------------- Thank you!!---------------");
}
}
