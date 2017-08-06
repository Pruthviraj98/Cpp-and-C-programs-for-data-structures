#include<bits/stdc++.h>
using namespace std;
#define max 10

class Stack
{
	public:
	int top;
	int a[max];
	Stack()
	{
		top=-1;
	}
	bool push(int x);
	int pop();
	int print();
	bool isempty(); 
};

bool Stack::push(int x)
{
	if(top>=max)
	{
		cout<<"overflow";
		return (false);
	}
	else
	{
		a[++top]=x;
		return(true);
	}
}
int Stack :: pop()
{
	if(isempty())
	{
		cout<<"underflow";
		return(false);
	}
	else
	{
		isempty();
		cout<<"\n popped element is\n "<<a[top];
		top--;
		return(a[top+1]);
	}
}
bool Stack:: isempty()
{
	return((top<0));
}
int Stack:: print()
{
	int i;
	for(i=top;i>0;i--)
	{
		cout<<a[i]<<"\t";
	}
}

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(30);
	s.push(10);
	s.push(20);
	s.push(30);	
	s.push(500);
	s.push(500);
	
	s.print();
	s.pop();
	s.pop();
	s.print();
	
}
