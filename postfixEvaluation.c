#include <stdio.h>
#include <ctype.h>
#include <conio.h>
void push(int item);
int pop();
void EvalPostfix(char postfix[]);
#define MAXSTACK 100 /*for max of stack*/
#define POSTFIXSIZE 100 /*define max number of characters in postfix expression*/

/* declare stackk and its top pointer to be use during postfix expression evaluation*/
int stack[MAXSTACK];
int top = -1; /*because arra index in C begins at 0*/
/*we can do this initialization somewhere else*/
int main()
{
	int i;
	/*declare character array to store postfix expression*/
	char postfix[POSTFIXSIZE];
	printf("ASSUMPTION: There are only four operators(*,/,+,-) in an expression and opereand is single digit only\n");
	printf("\nEnter postfix expression,\npress right parenthesis')' for end of expression:");

	/*take input of postfix expression from the user*/
	for(i=0;i<=POSTFIXSIZE-1;i++)
	{
		scanf("%c",&postfix[i]);
		if(postfix[i]==')')/* is ther any way to eliminate this if*/
		{
			break;
		}
	}
	/*call function to evaluate postfix expression*/
	EvalPostfix(postfix);

	getch();
}
/*define function that is used to input postfix expression and to evsluate it*/
void EvalPostfix(char postfix[])
{
	int i;
	char ch;
	int val;
	int A,B;

	/*evaluate postfix expression*/
	for(i=0;postfix[i]!=')';i++)
	{
		ch = postfix[i];
		if(isdigit(ch))
		{
			/*we saw an operand,push the digit onto stack -ch '0' is used for getting digit rather thabn ASCII code*/
			push(ch- '0');
		}
		else if(ch =='+'||ch == '-'||ch == '*'||ch == '/')
		{
			A =pop();
			B=pop();

			switch(ch)/*ch is an operator*/
			{
				case '*': 
				     val = B*A;
				     break;
				case '/':
				     val = B/A;
				     break;
				case '+':
				     val = B+A;
				     break;
				case '-':
				     val = B-A;
				     break;
			}push(val);
		}
	}printf("\nResult of expression evaluation : %d\n",pop());
}
void push(int item)
{
	if (top >= MAXSTACK - 1)
	{
		printf("Stack Overflow\n");
		return;
	}
	else
	{
		top = top +1;
		stack[top]=item;
	}
}
int pop()
{
	int item;
	if(top<0)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		item = stack[top];
		top = top - 1;
		return item;
	}
}