#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;//initialize the start to null always at the beginning
struct node *create(int num)//always call this instead of writing lengthy codes repeatedly 
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	return(temp);
}
struct node* insert_at_end(int num)
{
	struct node *temp, *temp1;
	temp1=start;
	temp=create(num);
	if(start==NULL)
{
	start=temp;	
	return;
}
	while(temp1->next!=NULL)
	{
	temp1=temp1->next;
	}
	temp1->next=temp;
	}
void display()
{
	struct node *temp;
	temp=start;
	while(temp->next!=NULL)
	{
	printf("%d\t",temp->data);
	temp=temp->next;
	}
printf("%d\t",temp->data);
printf("\n");
}
void insert_at_beg(int num)
{
	struct node *temp;
	temp=create(num);//added
	if(start==NULL)//added
{
	start=temp;	
	return;
}
	temp->next=start->next;//being carefull here!!
	start->next=temp;
}
int check()//function added
{
	if(start==NULL)
	{
		return(1);
	}
	return(0);
}
void delete_at_end()
{
if(check())
{
	printf("\n no elements \n");
	return;
}
	struct node *temp,*temp1;
	temp=temp1=start;
	while(temp1->next!=NULL)
	{
		temp=temp1;
		temp1=temp1->next;
	}
	temp->next=NULL;
	free(temp1);
}
int delete_at_beg()
{
if(check()==1)
{
	printf("\n no elements\n ");
	return;
}
	struct node *temp;
	temp=start;
	start=start->next;
	free(temp);

}
void insert_at_mid(int num, int pos)
{
	struct node* temp;
	struct node* temp1;
	temp=create(num);
	if(start==NULL)//always use == sign in if conditions :p
{
	start=temp;	
	return;
}
	temp1=start;
	while(pos>0)
	{
		temp1=temp1->next;
		pos--;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}	
void main()
{
insert_at_mid(2,3);
insert_at_beg(0);
insert_at_beg(0);
insert_at_beg(0);
insert_at_mid(2,2);
insert_at_end(3);
insert_at_beg(0);
insert_at_mid(2,3);
display();
delete_at_end();
delete_at_beg();
display();
}
