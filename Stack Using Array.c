#include <stdio.h>
#include <conio.h>
#include <string.h>
#define Max 6
int top=-1;
int stack[Max];
void push();
void pop();
void display();
void main()
{
    int choice;
	printf("\n----------**********----------\n");
	printf("\nStack Using Array Data Type\n");
	do
	{
		printf("\nWhat do you want to perform\n");
	    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nPlease Enter your choice : ");
        scanf("%d",&choice);
	    switch(choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			break;
		default:
			printf("\nInvalid Choice\n");
		}
	}while(choice!=4);
	getch();
}
void push()
{
	if(top == Max-1)
		printf("\nStack Overflow\n");
	else
	{
		top++;
		printf("\nEnter the number : ");
		scanf("%d",&stack[top]);
		printf("\nNumber Entered Into The Stack\n");
	}
}
void pop()
{
	if(top == -1)
		printf("\nStack Underflow\n");
	else
	{
		printf("\nThe deleted element is %d\n",stack[top]);
		top--;
	}
}
void display()
{
	int i;
	if(top == -1)
		printf("\nStack Underflow\n");
	else 
	{
		for(i=top;i>=0;i--)
		{
			printf("\n ---------------\n");
			printf("\n|\t%d\t|\n",stack[i]);
		}
	}

}