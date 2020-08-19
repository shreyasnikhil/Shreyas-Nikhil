#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 10
int stack[SIZE];
int top = -1;
void push(int value);
void pop();
void display();
int main()
{
	int choice,value;
	printf("What would you like to perform?\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	while(choice!=4)
	{
		printf("Enter The Choice: \n");
		scanf("%d",&choice);
		switch(choice)
	    {
		   case 1: printf("Enter the number:\n");
		           scanf("%d",&value);
		           push(value);
                   break;
		   case 2: pop();
		           break;
		   case 3: display();
		           break;
		   case 4: printf("Exit\n");
		           break;
		   default: printf("Invalid Choice\n");
	    }
	}
	return 0;
}
void push(int value)
{
	if(top==SIZE-1)
		printf("Stack Overflow\n");
	else
	{
		top++;
		stack[top]=value;
		printf("The pushed number is %d\n",stack[top] );
	}
}
void pop()
{
	if(top==-1)
		printf("Stack Underflow!\n");
	else
	{
		printf("The deleted item is %d\n",stack[top] );
		top--;
	}
}
void display()
{
	int i;
	if(top==-1)
		printf("Stack is empty\n");
	else
	{
		for(i=top;i>=0;i--)
			printf("%d\n",stack[i] );
	}
}
