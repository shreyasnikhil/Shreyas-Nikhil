#include <stdio.h>
#include <conio.h>
#define MAX 6

int CQ[MAX];
int front;
int rear;
int count;

void insertCQ()
{
	int data;
	if(count == MAX)
		printf("\nCircular Queue is Full\n");
	else
	{
		printf("\nEnter data: ");
		scanf("%d",&data);
		CQ[rear] = data;
		rear = (rear+1)% MAX;
		count++;
		printf("\nData inserted in the Circular Queue\n");
	}
} 
void deleteCQ()
{
	if(count == 0)
		printf("\n\n\tCircular Queue is Empty\n");
	else
	{
		printf("\nDeleted element from Circular is %d ",CQ[front]);
		front = (front+1)%MAX;
		count--;
	}
}
void displayCQ()
{
	int i,j;
	if(count == 0)
		printf("\n\nCircular Queue is Empty");
	else
	{
		printf("\nElements of circular Queue are : ");
		j = count;
		for(i=front;j!=0;j--)
		{
			printf("%d\t",CQ[i] );
			i=(i+1)%MAX;
		}
	}
}
int menu()
{
	int ch;
	
	printf("\n\tCircular Queue Operations Using Array...");
	printf("\n------------**************------------\n");
	printf("\n1.Insert");
	printf("\n2.Delete");
	printf("\n3.Display");
	printf("\n4.Quit");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	return ch;
}
void main()
{
	int ch;
	do
	{
		ch=menu();
		switch(ch)
		{
			case 1:
			      insertCQ();
			      break;
			case 2:
			      deleteCQ();
			      break;
			case 3:
			      displayCQ();
			      break;
			case 4:
			      return;
			default:
			      printf("\nInvalid Choice");
		}getch();
	}while(1);
}