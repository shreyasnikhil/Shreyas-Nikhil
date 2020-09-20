#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node{
	int val;
	struct node *next;
};
typedef struct node Node;
Node *head;
void main()
{
	int choice = 0;
	printf("\n=============**************=============\n");
	printf("\n STACK IMPLEMENTATION USING LINKED LIST\n");
	printf("\n=============**************=============\n");
	while(choice!=4)
	{
		printf("\n\nWhat Would You Like To Perform?\n1.Push\n2.Pop\n3.Display\n4.Exit\nPlease Enter Your Choice : ");
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
		default:
			break;
		}
	}
}
void push()
{
	int val;
	Node *ptr=(Node *)malloc(sizeof(Node));
	if(ptr==NULL)
		printf("\nCan't Insert!\n");
	else
	{
		printf("\nEnter the Value : ");
		scanf("%d",&val);
		if(head==NULL)
		{
			ptr->val = val;
			ptr->next = NULL;
			head = ptr;
		}
		else
		{
			ptr->val = val;
			ptr->next = head;
			head = ptr;
		}
		printf("\nNode Inserted\n");
	}
}
void pop()
{
	int item;
	Node *ptr;
	if(head == NULL)
		printf("\nUnderflow\n");
	else
	{
		item = head->val;
		ptr = head;
		head = head->next;
		free(ptr);
		printf("\nPopped item %d\n",item);
	}
}
void display()
{
	Node *ptr;
	ptr = head;
	if(ptr == NULL)
	{
		printf("\nStack is Empty\n");
	}
	else
	{
		printf("\nPrinting Values...\n");
		while(ptr!=NULL)
		{
			printf("\n+--+--+\n");
			printf("|  %d  |",ptr->val);
			ptr = ptr->next;
		}
	}
}